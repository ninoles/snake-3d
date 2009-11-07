/*
 * Game.cpp
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Plataform/Game.h"

using namespace plataform;

Game* Game::_gameSing = NULL;

Game* Game::getInstance(){
	if(_gameSing == 0){
		return _gameSing = new Game();
	}

	return _gameSing;
}

void Game::initDisplay(){
	_frameMan = new FrameManagement(800, 600, 32, false, true);
	_gameCurrentOption = GAME_NOTHING_OPTION;
}

void Game::setCurrentOption(Options __gameCurrent){
	_gameCurrentOption = __gameCurrent;
}

void Game::run(){

	while(_frameMan->getBaseFrame()->frameRun()){
		_frameMan->getBaseFrame()->drawFrame();

		switch(_gameCurrentOption){

			case GAME_LOAD_ARCHIVE_GAME:
				_gameCurrentOption = GAME_NOTHING_OPTION;
				break;

			case GAME_LOAD_ARCHIVE_HELP:
				_gameCurrentOption = GAME_NOTHING_OPTION;
				break;

			case GAME_LOAD_ARCHIVE_INFO_SCORE:
				_gameCurrentOption = GAME_NOTHING_OPTION;
				break;

			case GAME_SAVE_ARCHIVE_GAME:
				_gameCurrentOption = GAME_NOTHING_OPTION;
				break;

			case GAME_SAVE_ARCHIVE_PREF:
				_gameCurrentOption = GAME_NOTHING_OPTION;
				break;

			case GAME_NOTHING_OPTION:
				break;

		}
	}

}

