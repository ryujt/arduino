#ifndef RYUGAME_H
#define RYUGAME_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <LinkedList.h>


typedef void (*OnUpdateEvent) (int tick);


class GameControlBase
{
protected:
	Adafruit_PCD8544 *_LCD;
	void *_Engine;
	void *_Layer;
public:
	virtual void start() = 0;
	virtual void update(unsigned long tick) = 0;

	friend class GameEngine;
	friend class GameLayer;
};


class GameLayer
{
protected:
	Adafruit_PCD8544 *_LCD;
	void *_Engine;
private:
	LinkedList<GameControlBase *> _Controls = LinkedList<GameControlBase *>();
public:
	void addControl(GameControlBase *control);

	void start();
	void update(unsigned long tick);

	friend class GameEngine;
};


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
