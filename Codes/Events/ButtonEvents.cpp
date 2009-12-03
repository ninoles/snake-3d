/*
 * FrameManagement.h
 *
 *  Created on: 26/09/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Events/ButtonEvents.h"

using namespace Events;
using namespace file;
using namespace plataform;

using namespace std;

ButtonEvents::ButtonEvents(){
    _device = 0;
    _options = GAME_NOTHING_OPTION;
}

ButtonEvents::ButtonEvents(irr::IrrlichtDevice *__device){
	_device = __device;
	_options = GAME_NOTHING_OPTION;
}

void ButtonEvents::handler(int __idEvent){
	switch(__idEvent){


		/*
		 * Start Main Menu Options
		 */

		case GUI_ID_CREATE_GAME_BUTTON:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiNewGame.xml", 0);
        	break;

        case GUI_ID_LOAD_GAME_BUTTON:
        	_device->getGUIEnvironment()->addFileOpenDialog(L"Selecione um jogo salvo", true, 0, 1000);
        	break;

        case GUI_ID_SCORE_BUTTON:
        	_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiScore.xml", 0);
			break;

        case GUI_ID_HELP_GAME:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiAbout.xml", 0);
        	break;

        case GUI_ID_PREF_BUTTON:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiPref.xml", 0);

        	_options = GAME_LOAD_ARCHIVE_PREF;
        	break;

        case GUI_ID_MAIN_MENU_GAME:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiMainMenu.xml",0);
        	break;

        case GUI_ID_QUIT_GAME:
        	_device->closeDevice();
        	break;

		/*
		 * End Main Menu Options
		 */

        /*
         * Start FileOpenDialog Options
         */

        case  GUI_ID_FILE_OPEN:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiError.xml",0);
        	break;

        /*
         * End FileOpenDialog Options
         */

        /*
         * Start File Record/Read Options
         */

        case GUI_ID_SAVE_PREF:
        	_options = GAME_SAVE_ARCHIVE_PREF;

			//Save in the file.

			_fileMan = new FileManagement("conf/gameConf", ".dat");
			_fileMan->openFileWrite(false);
			_fileMan->saveConfigurationVideo(atoi(GUIManagement::getTokens("x", GUIManagement::getTextElement(800, _device->getGUIEnvironment()->getRootGUIElement()))[0].c_str())
												, atoi(GUIManagement::getTokens("x", GUIManagement::getTextElement(800, _device->getGUIEnvironment()->getRootGUIElement()))[1].c_str())
												, 32, ((irr::gui::IGUICheckBox*)GUIManagement::getElement(801, _device->getGUIEnvironment()->getRootGUIElement()))->isChecked(), false
												, ((irr::gui::IGUICheckBox*)GUIManagement::getElement(802, _device->getGUIEnvironment()->getRootGUIElement()))->isChecked()
												, ((irr::gui::IGUICheckBox*)GUIManagement::getElement(803, _device->getGUIEnvironment()->getRootGUIElement()))->isChecked());

			_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiMainMenu.xml",0);
			break;

        case GUI_ID_SAVE_TYPE_GAME:
        	_options = GAME_START_MATCH;

        	//Save in the file

        	_fileMan = new FileManagement("conf/matchConf", ".dat");
        	_fileMan->openFileWrite(false);

        	_fileMan->saveElement(GUIManagement::getTextElement(600, _device->getGUIEnvironment()->getRootGUIElement()));
        	_fileMan->saveElement(GUIManagement::getTextElement(601, _device->getGUIEnvironment()->getRootGUIElement()));
        	_fileMan->saveElement(GUIManagement::toString(((irr::gui::IGUICheckBox*)GUIManagement::getElement(602, _device->getGUIEnvironment()->getRootGUIElement()))->isChecked()));
        	_fileMan->saveElement(GUIManagement::toString(((irr::gui::IGUICheckBox*)GUIManagement::getElement(603, _device->getGUIEnvironment()->getRootGUIElement()))->isChecked()));
        	_fileMan->saveElement(GUIManagement::getTextElement(604, _device->getGUIEnvironment()->getRootGUIElement()));

        	_fileMan->closeWrite();

        	_device->getGUIEnvironment()->clear();
			break;

        case GUI_ID_SAVE_CURRENT_GAME:
        	_options = GAME_SAVE_CURRENT_GAME;
        	_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiError.xml",0);
			break;

		/*
		 * End File Record/Read Options
		 */

		/*
		 * Start Players Score Options
		 */

        case GUI_ID_LOAD_SCORE_PLAYERS:
        case GUI_ID_LOAD_WINS_PLAYERS:
        case GUI_ID_LOAD_MATCH_PLAYERS:
        	_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiError.xml",0);
			break;

		/*
		 * End Players Score Options
		 */

	}
}

void ButtonEvents::setGameOption(gameOptions __options){
	_options = __options;
}

int ButtonEvents::getGameOption(){
	return _options;
}
