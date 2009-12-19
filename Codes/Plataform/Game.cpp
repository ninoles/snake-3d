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

}


void platform::Game::generatMap(){
/*
	//Teste for print mesh
	_frameMan->getBaseFrame()->setColor(0,255,255,255);

	tmp = new base::FrameSceneNode(_frameMan->getBaseFrame()->addAnimetedSceneNode("cubo.3DS"), 1);

	tmp->getSceneNode()->setPosition(irr::core::vector3df(0, 50, 0));
	tmp->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	tmp->getSceneNode()->setMaterialTexture(0, _frameMan->getBaseFrame()->getVideoDriver()->getTexture("/home/henrique/workspace/snake project/snake-3d/images/logo.png"));

	_frameMan->getBaseFrame()->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0,0,30), irr::core::vector3df(0,5,0));

	_frameMan->getBaseFrame()->getEventReceiver()->getNodeMoviment()->insertNode(tmp);
	_frameMan->getBaseFrame()->getEventReceiver()->getNodeMoviment()->insertKeysFromNode(1, irr::KEY_UP, irr::KEY_LEFT, irr::KEY_RIGHT, irr::KEY_DOWN);
	_frameMan->getBaseFrame()->getEventReceiver()->getNodeMoviment()->setMovementSpeed(3.f);

	tmp2 = new base::FrameSceneNode(_frameMan->getBaseFrame()->addAnimetedSceneNode("cubo.3DS"), 2);

	tmp2->getSceneNode()->setPosition(irr::core::vector3df(100, 0, 0));
	tmp2->getSceneNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	tmp2->getSceneNode()->setMaterialTexture(0, _frameMan->getBaseFrame()->getVideoDriver()->getTexture("/home/henrique/workspace/snake project/snake-3d/images/logo.png"));

	_frameMan->getBaseFrame()->getEventReceiver()->getNodeMoviment()->insertNode(tmp2);
	_frameMan->getBaseFrame()->getEventReceiver()->getNodeMoviment()->insertKeysFromNode(2, irr::KEY_KEY_W, irr::KEY_KEY_A, irr::KEY_KEY_D, irr::KEY_KEY_S);

	MeshCollision* meshA = new MeshCollision(_gameManagement->getNewtonWorld(), tmp);
	MeshCollision* meshB = new MeshCollision(_gameManagement->getNewtonWorld(), tmp2);

	meshA->createCollision();
	meshB->createCollision();
*/
}

void platform::Game::run(){
    while(_frameMan->getBaseFrame()->isVisible())
        _frameMan->getBaseFrame()->show();
}
