/*
 * Match.cpp
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

 #include "../../Headers/Platform/Match.h"

platform::Match::Match(){
	_config = new file::ConfMatch();
	_intelligence = false;
	_maxPoints = 0;
	_numberOfPlayers = 0;
	_players = new Players::GroupPlayers();
	_map = new platform::Map();
}

void platform::Match::setProperties(){
	_config->readConfiguration();

	_dificulty = _config->getDificulty();
	_intelligence = _config->isIntelligence();
	_maxPoints = _config->getMaxPoints();
	_numberOfPlayers = _config->getNumberOfPlayers();

	_players = new Players::GroupPlayers(_numberOfPlayers);
}

void platform::Match::initMatch(irr::video::IVideoDriver *__driver, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW){

	//Starting the game data
	setProperties();

	_map = new platform::Map(__sceneManager, __driver, __newtonW);
	_points = new platform::Point(__sceneManager, __newtonW, 100);

	for(int k = 0; k < _players->getNumberOfPlayers(); k++)
		_players->getAllPlayers()->get(k).createSnake(randomPositionPlayers(), __sceneManager, __newtonW);

}

void platform::Match::runMatch(){
	if(!endMatch() && _points->isRepetitions()){
		randomPoints();
		_players->moveSnakesToForward();
	}
}

void platform::Match::randomPoints(){
	int positionX = 0,
		positionZ = 0;

	srand(time(NULL));

	positionX = rand();
	positionZ = rand();

	while((positionX < 0 || positionX > 13) && (positionZ < 0 || positionZ > 13)){
		positionX = rand();
		positionZ = rand();
	}

	_points->insertPointInPosition(irr::core::vector3df(positionX, _points->getAnimatedNode()->getPosition().Y, positionZ));

}

void platform::Match::randomBonus(){

}

irr::core::vector3df platform::Match::randomPositionPlayers(){

	irr::core::vector3df position;

	srand(time(NULL));

	position.X = rand();
	position.Z = rand();

	while((position.X < 5 || position.X > 13) && (position.Z < 5 || position.Z > 13)){
		position.X = rand();
		position.Z = rand();
	}

	position.Y = POSITION_Y_MAP;

	return position;
}

bool platform::Match::endMatch(){
	for(int k = 0; k < _players->getNumberOfPlayers(); k++)
		if(_players->getScoreByPlayer(_players->getAllPlayers()->get(k)) == _maxPoints)
			return true;

	return false;
}

Players::GroupPlayers* platform::Match::getGroupPlayers(){
	return _players;
}

platform::Map* platform::Match::getMap(){
	return _map;
}
