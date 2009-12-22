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

	/*_frameMan->getBaseFrame()->setColor(0,255,255,255);

	base::FrameCameraFPS *_camera = new base::FrameCameraFPS(_gamePlay->getNewtonWorld(), _frameMan->getBaseFrame()->getSceneManager(), 0);
	_node1 = new base::FrameAnimatedNode(_gamePlay->getNewtonWorld(), _frameMan->getBaseFrame()->getSceneManager(), 1);
	_node2 = new base::FrameAnimatedNode(_gamePlay->getNewtonWorld(), _frameMan->getBaseFrame()->getSceneManager(), 2);

	_node1->createNode("cubo.3ds", irr::core::vector3df(0,0,0), irr::core::vector3df(0,10,0), irr::core::vector3df(1.0f,1.0f,1.0f));
	_node1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node1->setTexture(0, _frameMan->getBaseFrame()->getTexture("images/logo.png"));

	_node1->insertKeyMoviment(irr::KEY_KEY_A);
	_node1->insertKeyMoviment(irr::KEY_KEY_D);

	_frameMan->getBaseFrame()->getNodeMoviment()->setMovementSpeed(4.0f);
	_frameMan->getBaseFrame()->getNodeMoviment()->insertMovimentNode(_node1, _node1->getKeyMoviment());

	_node2->createNode("cubo.3ds", irr::core::vector3df(0,0,0), irr::core::vector3df(10.75,10,0), irr::core::vector3df(1.0f,1.0f,1.0f));
	_node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node2->setTexture(0, _frameMan->getBaseFrame()->getTexture("images/detailmap3-teste.jpg"));

	_node1->createCollision();
	_node2->createCollision();

	base::FrameTerrainSceneNode *_terrain = new base::FrameTerrainSceneNode(_gamePlay->getNewtonWorld(),_frameMan->getBaseFrame()->getSceneManager(), 0);

	_terrain->createTerrain("images/terrain-heightmap-teste.bmp", 0, irr::video::SColor(255, 255, 255, 255), 5, irr::scene::ETPS_17, 4);
	_terrain->setPosition(0,0,0);
	_terrain->setScale(40.f, 4.4f, 40.f);
	_terrain->setRotation(0,0,0);
	_terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_terrain->setTexture(0, _frameMan->getBaseFrame()->getTexture("images/terrain-texture-teste.jpg"));
	_terrain->getTerrainNode()->setMaterialTexture(1,_frameMan->getBaseFrame()->getTexture("images/detailmap3-teste.jpg"));
	_terrain->repaint();

	_terrain->getTerrainNode()->scaleTexture(1.0f, 20.0f);

	_camera->createCamera(0, 100.0f, 0.5f, 0, 0, false, 0);
	_camera->setPosition(0, -20, 10);
	*/

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
