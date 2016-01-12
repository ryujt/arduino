#include <RyuGame.h>

/* class GameLayer */

void GameLayer::addControl(GameControlBase *control)
{
	 control->_LCD = _LCD;
	 control->_Engine = _Engine;
	 control->_Layer = this;

	_Controls.add(control);
}

void GameLayer::start()	
{
	for (int i=0; i<_Controls.size(); i++) {
		GameControlBase *control = _Controls.get(i);
		control->start();
	}
}

void GameLayer::update(unsigned long tick)
{
	for (int i=0; i<_Controls.size(); i++) {
		GameControlBase *control = _Controls.get(i);
		control->update(tick);
	}
}
	

/* class GameEngine */

GameLayer *GameEngine::addLayer()
{
	GameLayer *layer = new GameLayer();

	layer->_LCD = &_LCD;
	layer->_Engine = this;

	_Layers.add(layer);

	return layer;
}

void GameEngine::start()
{
	_LCD.begin();
	_LCD.setContrast(50);
	_LCD.clearDisplay();
	_LCD.display();

	_OldTick = millis();

	for (int i=0; i<_Layers.size(); i++) {
		GameLayer *layer = _Layers.get(i);
		layer->start();
	}
}
	
void GameEngine::update()
{
	unsigned long tick = millis();
	unsigned long term = 0;
	if (tick > _OldTick) term = tick - _OldTick;
	_OldTick = tick;

	if (_OnBeforeUpdate != NULL) _OnBeforeUpdate(term);

	_LCD.clearDisplay();

	for (int i=0; i<_Layers.size(); i++) {
		GameLayer *layer = _Layers.get(i);
		layer->update(term);
	}

	_LCD.display();

	if (_OnAfterUpdate != NULL) _OnAfterUpdate(term);
}

void GameEngine::setOnBeforeUpdate(OnUpdateEvent event)
{
	_OnBeforeUpdate = event;
}	

void GameEngine::setOnAfterUpdate(OnUpdateEvent event)
{
	_OnAfterUpdate = event;
}
