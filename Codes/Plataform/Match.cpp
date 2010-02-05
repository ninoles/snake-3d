/*
 * Match.cpp
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Match.h"
#include <iostream>

platform::Match::Match(){
	_config = new file::ConfMatch();
	_intelligence = false;
	_maxPoints = 0;
	_numberOfPlayers = 0;
	_players = new Players::GroupPlayers();
	_map = new platform::Map();
}

void platform::Match::setProperties(){
	_config->setArchiveRead("conf/config_match.xml");
	_config->readConfiguration();

	_dificulty = _config->getDificulty();
	_intelligence = _config->isIntelligence();
	_maxPoints = _config->getMaxPoints();
	_numberOfPlayers = _config->getNumberOfPlayers();

	for(int k = 0; k < _numberOfPlayers; k++){
		Players::Player tmp;
		_players->addPlayer(tmp);
		_players->getAllPlayers()->get(k).getSnake()->insertMoviment(k+1);
	}
}

void platform::Match::initMatch(irr::video::IVideoDriver *__driver, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW){

	//Starting the game data
	setProperties();

	_map = new platform::Map(__sceneManager, __driver, __newtonW);
	_points = new platform::Point(__sceneManager, __newtonW, 100);

	_points->setMaxPoints(_maxPoints);

	for(int k = 0; k < _players->getNumberOfPlayers(); k++)
		_players->getAllPlayers()->get(k).createSnake(randomPositionPlayers(), __sceneManager, __newtonW);

}

bool platform::Match::runMatch(){
	return endMatch();
}

void platform::Match::setVisiblePoint(bool __visible){
	_points->getAnimatedNode()->setVisible(__visible);
}

void platform::Match::randomPoints(){
	irr::core::vector3df position;

	srand(time(NULL));

	position.X = (rand() % POSITION_X_MAP) + 3;
	position.Y = POSITION_Y_MAP + 0.5;
	position.Z = (rand() % POSITION_Z_MAP) + 3;

	_points->insertPointInPosition(position);

}

void platform::Match::randomBonus(){

}

irr::core::vector3df platform::Match::randomPositionPlayers(){

	irr::core::vector3df position;

	srand(time(NULL));

	position.X = (rand() % POSITION_X_MAP) + 1;
	position.Y = POSITION_Y_MAP + 0.25;
	position.Z = (rand() % POSITION_Z_MAP) + 1;


	return position;

}

bool platform::Match::endMatch(){
	for(int k = 0; k < _players->getNumberOfPlayers(); k++)
		if(_players->getScoreByPlayer(_players->getAllPlayers()->get(k)) == _maxPoints)
			return true;

	return false;
}

bool platform::Match::isVisiblePoint(){
	return _points->getAnimatedNode()->getAnimatedMesh()->isVisible();
}

Players::GroupPlayers* platform::Match::getGroupPlayers(){
	return _players;
}

platform::Map* platform::Match::getMap(){
	return _map;
}

platform::Point* platform::Match::getPoint(){
	return _points;
}
