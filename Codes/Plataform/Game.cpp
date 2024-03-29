/*
 * Game.cpp
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Game.h"

platform::Game* platform::Game::_gameSing = NULL;

platform::Game* platform::Game::getInstance(){
	if(_gameSing == 0){
		return _gameSing = new Game();
	}

	return _gameSing;
}

void platform::Game::initDisplay(){
    file::ConfFrame *conf = new file::ConfFrame();
    conf->setArchiveRead("conf/config_video.xml");
    conf->readConfigurations();

    _frameMan = new platform::FrameManagement(conf->readWidth(), conf->readHeigth(), conf->readBitsPerPixel(), conf->readFullScreen(),
                            conf->readStencilBuffer(), conf->readActivateJoy(), conf->readAntiAliasing());

    _threadMatch = new platform::ThreadMatch();
}

void platform::Game::run(){
    while(_frameMan->getBaseFrame()->isVisible()){

    	_frameMan->getBaseFrame()->show();

        if(_frameMan->getBaseFrame()->getButtonEvents()->getGameOption() == 7){
        	 _gamePlay = new platform::Gameplay(_frameMan->getBaseFrame()->getSceneManager(), _frameMan->getBaseFrame()->getVideoDriver());

        	_gamePlay->initMatch();
			_gamePlay->randomMap();

			_threadMatch->createThread(_gamePlay);

			_frameMan->getBaseFrame()->getButtonEvents()->setGameOption(Events::GAME_PLAY_GAME);
			_frameMan->getBaseFrame()->setModeCursor(false);
        }
        else if (_frameMan->getBaseFrame()->getButtonEvents()->getGameOption() == 8){
        	_gamePlay->run();
        }

        _frameMan->getBaseFrame()->getSceneManager()->drawAll();
        _frameMan->getBaseFrame()->getGUIEnviroment()->drawAll();
        _frameMan->getBaseFrame()->getVideoDriver()->endScene();

    }
}
