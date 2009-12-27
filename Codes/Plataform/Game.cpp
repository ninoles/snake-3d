/*
 * Game.cpp
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Game.h"

#include <iostream.h>

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

	_gamePlay = new physis::Gameplay(_frameMan->getBaseFrame()->getSceneManager());

}


void platform::Game::generatMap(){

	_frameMan->getBaseFrame()->setColor(0,255,255,255);

	base::FrameCameraFPS *_camera = new base::FrameCameraFPS(_gamePlay->getNewtonWorld(), _frameMan->getBaseFrame()->getSceneManager(), 0);
	_node1 = new base::FrameAnimatedNode(_gamePlay->getNewtonWorld(), _frameMan->getBaseFrame()->getSceneManager(), 1);

	_node1->createNode("meshes/mapa_1_teste.3ds", irr::core::vector3df(0,0,0), irr::core::vector3df(0,10,0), irr::core::vector3df(1.0f,1.0f,1.0f));
	_node1->setAnimationSpeed(10);
	_node1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node1->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);

	_camera->createCamera(0, 10.f, 0.02f, 0, 0, false, 0);
	_camera->setPosition(15, 10, -10);
	_camera->repaint();

}

void platform::Game::run(){
    while(_frameMan->getBaseFrame()->isVisible()){

    	_frameMan->getBaseFrame()->show();

        if(_frameMan->getBaseFrame()->getButtonEvents()->getGameOption() == 7){
        	generatMap();
        	_frameMan->getBaseFrame()->getButtonEvents()->setGameOption(Events::GAME_NOTHING_OPTION);
        }

    }
}
