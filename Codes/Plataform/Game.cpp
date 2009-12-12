/*
 * Game.cpp
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Game.h"
#include <iostream>

using namespace plataform;
using namespace Events;
using namespace std;

Game* Game::_gameSing = NULL;

Game* Game::getInstance(){
	if(_gameSing == 0){
		return _gameSing = new Game();
	}

	return _gameSing;
}

void Game::initDisplay(){
	_fileMan = new FileManagement("conf/gameConf", ".dat");
	_fileMan->openFileRead();

	_frameMan = new FrameManagement(atoi(_fileMan->getElement().c_str()), atoi(_fileMan->getElement().c_str())
									, atoi(_fileMan->getElement().c_str()) , GUIManagement::toBoolean(_fileMan->getElement())
									, GUIManagement::toBoolean(_fileMan->getElement()));

	_fileMan->closeRead();

	_frameMan->getBaseFrame()->setResizable(false);
}


void Game::generatMap(){
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

void Game::swapGUI(int __options){

	string tmp = "";

	switch(__options){

		case GAME_LOAD_ARCHIVE_GAME:
			_fileMan = new FileManagement("conf/matchConf", ".txt");
			_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->setGameOption(GAME_NOTHING_OPTION);
			break;

		case GAME_LOAD_ARCHIVE_HELP:
			_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->setGameOption(GAME_NOTHING_OPTION);
			break;

		case GAME_LOAD_ARCHIVE_INFO_SCORE:
			_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->setGameOption(GAME_NOTHING_OPTION);
			break;

		case GAME_SAVE_ARCHIVE_GAME:
			_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->setGameOption(GAME_NOTHING_OPTION);
			break;

		case GAME_SAVE_ARCHIVE_PREF:

			_frameMan->getBaseFrame()->getDevice()->drop();
			initDisplay();

			_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->setGameOption(GAME_NOTHING_OPTION);
			break;

		case GAME_LOAD_ARCHIVE_PREF:
			_fileMan = new FileManagement("conf/gameConf", ".dat");
			_fileMan->openFileRead();

			tmp = _fileMan->getElement();

			if(tmp == "640")
				((irr::gui::IGUIComboBox*)GUIManagement::getElement(800, _frameMan->getBaseFrame()->getDevice()->getGUIEnvironment()->getRootGUIElement()))->setSelected(0);
			else if(tmp == "800")
				((irr::gui::IGUIComboBox*)GUIManagement::getElement(800, _frameMan->getBaseFrame()->getDevice()->getGUIEnvironment()->getRootGUIElement()))->setSelected(1);
			else if(tmp == "1024")
				((irr::gui::IGUIComboBox*)GUIManagement::getElement(800, _frameMan->getBaseFrame()->getDevice()->getGUIEnvironment()->getRootGUIElement()))->setSelected(2);

			_fileMan->getElement();
			_fileMan->getElement();

			((irr::gui::IGUICheckBox*)GUIManagement::getElement(801, _frameMan->getBaseFrame()->getDevice()->getGUIEnvironment()->getRootGUIElement()))->setChecked(GUIManagement::toBoolean(_fileMan->getElement()));

			_fileMan->getElement();

			((irr::gui::IGUICheckBox*)GUIManagement::getElement(802, _frameMan->getBaseFrame()->getDevice()->getGUIEnvironment()->getRootGUIElement()))->setChecked(GUIManagement::toBoolean(_fileMan->getElement()));

			((irr::gui::IGUICheckBox*)GUIManagement::getElement(803, _frameMan->getBaseFrame()->getDevice()->getGUIEnvironment()->getRootGUIElement()))->setChecked(GUIManagement::toBoolean(_fileMan->getElement()));

			_fileMan->closeRead();

			_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->setGameOption(GAME_NOTHING_OPTION);
			break;

		case GAME_START_MATCH:
			generatMap();
			_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->setGameOption(GAME_NOTHING_OPTION);

			break;

		case GAME_NOTHING_OPTION:
			break;

	}
}

void Game::run(){

	while(_frameMan->getBaseFrame()->frameRun()){
		_frameMan->getBaseFrame()->drawFrame();

		swapGUI(_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->getGameOption());

	}
}
