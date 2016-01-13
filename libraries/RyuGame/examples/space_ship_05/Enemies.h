#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"


// How offent do enemy appear.  Large number get low chance.
#define chance_enemy 20

#define enemy_speed 100


static const unsigned char PROGMEM enemy_image[] =
{ 
        B00011000,
        B00111100,
        B01111110,
        B11011011,
        B11111111,
        B01011010,
        B10000001,
        B01000010
};

class Enemy : public GameControlBase
{
private:
        int _TickCount = 0;
public:
        void start() 
        {
                _ID = Enemy_ID;

                _X = rand() % 84;
                _Y = -5;

                _HitSize = 3; 
        }

        void update(unsigned long tick) 
        {
                _LCD->drawBitmap(_X-3, _Y-3, enemy_image, 8, 8, BLACK);                
 
                _TickCount = _TickCount + tick;
                if (_TickCount > enemy_speed) {
                        _Y = _Y + (_TickCount / enemy_speed);
                        _TickCount = _TickCount % enemy_speed;
                }

                if (_Y > 52) _IsDeleted = true;
        }
};


class Enemies : public GameControlBase
{
private:
public:
	void start() 
	{
                srand(analogRead(0));
	}

	void update(unsigned long tick) 
	{
                if ((rand() % chance_enemy) != 0) return;

                Enemy *enemy = new Enemy();
                enemy->start();

                GameLayer *layer = (GameLayer *) _Layer;
                layer->addControl(enemy);
	}
};
