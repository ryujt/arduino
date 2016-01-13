#include <RyuGame.h>


/* class GameControlBase */
		
bool GameControlBase::checkCollisionWith(GameControlBase *control)
{
	if (_IsEnabled == false) return false;

	int hit_size = _HitSize + control->_HitSize;

	int x_distance = abs(_X - control->_X);
	int y_distance = abs(_Y - control->_Y);

	if (x_distance > hit_size) return false;
	if (y_distance > hit_size) return false;

	hit_size = hit_size * hit_size;
	x_distance = x_distance * x_distance;
	y_distance = y_distance * y_distance;

	return hit_size >= (x_distance + y_distance);
}

GameControlBase *GameControlBase::checkCollision()
{
	if (_IsEnabled) return ((GameLayer *) _Layer)->checkCollision(this);
	else return NULL;
}
			
bool GameControlBase::getIsEnabled()
{
	return _IsEnabled;
}

void GameControlBase::setIsEnabled(bool value)
{
	_IsEnabled = value;
}

bool GameControlBase::getIsDeleted()
{
	return _IsDeleted;
}

void GameControlBase::setIsDeleted(bool value)
{
	_IsDeleted = value;
}


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
		if (control->_IsEnabled) control->start();
	}
}

void GameLayer::update(unsigned long tick)
{
	for (int i=0; i<_Controls.size(); i++) {
		GameControlBase *control = _Controls.get(i);
		if (control->_IsEnabled) control->update(tick);
	}

	for (int i=_Controls.size()-1; i>=0; i--) {
		GameControlBase *control = _Controls.get(i);
		if (control->_IsDeleted) {
			_Controls.remove(i);
			delete control;
		}
	}
}
	
GameControlBase *GameLayer::checkCollision(GameControlBase *object)
{
	for (int i=0; i<_Controls.size(); i++) {
		GameControlBase *control = _Controls.get(i);

		if (control == object) continue;

		if (control->checkCollisionWith(object)) return control;
	}

	return NULL;
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
