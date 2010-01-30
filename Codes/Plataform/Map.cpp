/*
 * Map.cpp
 *
 *  Created on: 25/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Map.h"

platform::Map::Map(irr::scene::ISceneManager *__sceneManager, irr::video::IVideoDriver *__videoDriver, NewtonWorld *__newtonW){
	_sceneManager = __sceneManager;
	_videoDriver = __videoDriver;
	_newtonW = __newtonW;
	_numberMap = -1;
}

platform::Map::Map(){
	_numberMap = -1;
}

void platform::Map::initMaps(irr::scene::ISceneManager *__sceneManager, irr::video::IVideoDriver *__videoDriver, NewtonWorld *__newtonW){
	_sceneManager = __sceneManager;
	_videoDriver = __videoDriver;
	_newtonW = __newtonW;

	_mapOne = new base::FrameAnimatedNode(_newtonW, _sceneManager, 0);
	_mapTwo = new base::FrameAnimatedNode(_newtonW, _sceneManager, 1);
	_mapThree = new base::FrameAnimatedNode(_newtonW, _sceneManager, 2);
	_mapFour  = new base::FrameAnimatedNode(_newtonW, _sceneManager, 3);
	_skyBox = new base::FrameSkyBox(_newtonW, _sceneManager, 4);

	_mapOne->setPosition(POSITION_X_MAP, POSITION_Y_MAP, POSITION_Z_MAP);
	_mapTwo->setPosition(POSITION_X_MAP, POSITION_Y_MAP, POSITION_Z_MAP);
	_mapThree->setPosition(POSITION_X_MAP, POSITION_Y_MAP, POSITION_Z_MAP);
	_mapFour->setPosition(POSITION_X_MAP, POSITION_Y_MAP, POSITION_Z_MAP);

	_mapOne->setScale(SCALE_X_MAP, SCALE_Y_MAP, SCALE_Z_MAP);
	_mapTwo->setScale(SCALE_X_MAP, SCALE_Y_MAP, SCALE_Z_MAP);
	_mapThree->setScale(SCALE_X_MAP, SCALE_Y_MAP, SCALE_Z_MAP);
	_mapFour->setScale(SCALE_X_MAP, SCALE_Y_MAP, SCALE_Z_MAP);
}

void platform::Map::loadSkyBox(){
	_skyBox->createNode(_videoDriver->getTexture(SKY_TOP), _videoDriver->getTexture(SKY_BOTTOM), _videoDriver->getTexture(SKY_LEFT),
			_videoDriver->getTexture(SKY_RIGHT), _videoDriver->getTexture(SKY_FRONT), _videoDriver->getTexture(SKY_BACK), 0);
}

void platform::Map::generateRandomMap(){
	srand(time(NULL));

	int number = (rand() % 4)+1;
	_numberMap = number;

	switch(number){

		case 1:
			_mapOne->createNode(MAP_ONE);
			break;
		case 2:
			_mapTwo->createNode(MAP_TWO);
			break;
		case 3:
			_mapThree->createNode(MAP_THREE);
			break;
		case 4:
			_mapFour->createNode(MAP_FOUR);
			break;

	}

}

void platform::Map::flushScene(){
	_sceneManager->clear();
}

base::FrameAnimatedNode* platform::Map::getMap(){
	switch(_numberMap){

		case 1:
			return _mapOne;
		case 2:
			return _mapTwo;
		case 3:
			return _mapThree;
		case 4:
			return _mapFour;
		default:
			return NULL;
	}
}

