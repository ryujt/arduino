#ifndef RYUGAME_H
#define RYUGAME_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <LinkedList.h>


class GameEngine;
class GameLayer;

class GameControlBase
{
protected:
	Adafruit_PCD8544 *_LCD;
	GameEngine *_Engine;
	GameLayer *_Layer;

	int _ID = 0;

	int _X = 0;
	int _Y = 0;

	// Radius of hit area.  
	// _HitSize is limitation of distance when check collision of two GameControlBase objects.
	int _HitSize = 0;

	bool _IsEnabled = true;	
	bool _IsDeleted = false;	
private:
	bool checkCollisionWith(GameControlBase *control);
public:
	virtual void start() = 0;
	virtual void update(unsigned long tick) = 0;

	GameControlBase *checkCollision();

	int getID();
	void setID(int value);

	int getX();
	void setX(int value);

	int getY();
	void setY(int value);

	bool getIsEnabled();
	void setIsEnabled(bool value);

	bool getIsDeleted();
	void setIsDeleted(bool value);

	friend class GameEngine;
	friend class GameLayer;
};

class GameLayer
{
protected:
	Adafruit_PCD8544 *_LCD;
	GameEngine *_Engine;
private:
	LinkedList<GameControlBase *> _Controls = LinkedList<GameControlBase *>();
private:
	GameControlBase *checkCollision(GameControlBase *control);
public:
	void addControl(GameControlBase *object);

	void start();
	void update(unsigned long tick);

	friend class GameEngine;
	friend class GameControlBase;
};

typedef void (*OnUpdateEvent) (int tick);

class GameEngine
{
private:
	Adafruit_PCD8544 _LCD;

	unsigned long _OldTick;

	LinkedList<GameLayer *> _Layers = LinkedList<GameLayer *>();

	OnUpdateEvent _OnBeforeUpdate = NULL;
	OnUpdateEvent _OnAfterUpdate = NULL;
public:
	GameEngine(int8_t SCLK, int8_t DIN, int8_t DC, int8_t CS, int8_t RST) 
		: _LCD(SCLK, DIN, DC, CS, RST)
		{}

	GameLayer *addLayer();

	void start();
	void update();

	void setOnBeforeUpdate(OnUpdateEvent event);
	void setOnAfterUpdate(OnUpdateEvent event);
};


#endif // RYUGAME_H
