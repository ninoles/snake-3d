/*
 * ButtonEvents.h
 *
 *  Created on: 26/09/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Events/ButtonEvents.h"

Events::ButtonEvents::ButtonEvents(){
    _device = 0;
    _options = GAME_NOTHING_OPTION;
}

Events::ButtonEvents::ButtonEvents(irr::IrrlichtDevice *__device){
	_device = __device;
	_options = GAME_NOTHING_OPTION;
	_confFrame = new file::ConfFrame(__device);
	_confMatch = new file::ConfMatch(__device);
}

void Events::ButtonEvents::handler(int __idEvent){

	_rootElement = _device->getGUIEnvironment()->getRootGUIElement();

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
        	_confFrame->setArchiveWrite("conf/confFrame.xml");
        	_confFrame->writeConfigurations(GUIManagement::getTokens(GUIManagement::getTextElement(800, _rootElement), L" x ", 1),
        			GUIManagement::getTokens(GUIManagement::getTextElement(800, _rootElement), L" x ", 2), L"32",
        			GUIManagement::getTextElement(803, _rootElement), GUIManagement::getTextElement(802, _rootElement),
        			GUIManagement::getTextElement(801, _rootElement), false);

			_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiMainMenu.xml",0);
			break;

        case GUI_ID_SAVE_TYPE_GAME:
        	_options = GAME_START_MATCH;

        	//Save in the file
        	_confMatch->setArchiveWrite("conf/confMatch.xml");
        	_confMatch->writeConfigurations(GUIManagement::getTextElement(600, _rootElement), GUIManagement::getTextElement(601, _rootElement),
        			GUIManagement::getTextElement(604, _rootElement), GUIManagement::getTextElement(602, _rootElement),
        			GUIManagement::getTextElement(603, _rootElement));
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

void Events::ButtonEvents::setGameOption(gameOptions __options){
	_options = __options;
}

int Events::ButtonEvents::getGameOption(){
	return _options;
}

file::ConfFrame* Events::ButtonEvents::getFrameConfig(){
	return _confFrame;
}

file::ConfMatch* Events::ButtonEvents::getMatchConfig(){
	return _confMatch;
}
