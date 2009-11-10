/*
 * Game.cpp
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Plataform/Game.h"

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

void Game::run(){

	string tmp = "";

	while(_frameMan->getBaseFrame()->frameRun()){
		_frameMan->getBaseFrame()->drawFrame();

		switch(_frameMan->getBaseFrame()->getEventReceiver()->getButtonEvents()->getGameOption()){

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
			case GAME_NOTHING_OPTION:
				break;

		}
	}

}
