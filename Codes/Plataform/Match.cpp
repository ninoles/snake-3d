/*
 * Match.cpp
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

 #include "../../Headers/Platform/Match.h"

platform::Match::Match(){
	_config = new file::ConfMatch();
	_dificulty = 0;
	_intelligence = false;
	_maxPoints = 0;
	_numberOfPlayers = 0;
}

void platform::Match::setProperties(){
	_config->readConfiguration();

	_dificulty = _config->getDificulty();
	_intelligence = _config->isIntelligence();
	_maxPoints = _config->getMaxPoints();
	_numberOfPlayers = _config->getNumberOfPlayers();

	_players = new Players::GroupPlayers(_numberOfPlayers);
}
