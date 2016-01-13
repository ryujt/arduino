#include <Arduino.h>
#include <RyuGame.h>
#include "Globals.h"

class ScoreBoard : public GameControlBase
{
private:
        int _Score = 0;
public:
	void start() 
	{
	}

	void update(unsigned long tick) 
	{
                if (is_game_end == false) _Score = _Score + tick;

                _LCD->setTextSize(1);
                _LCD->setCursor(0,0);
                _LCD->println(_Score / 100);                
	}
};
