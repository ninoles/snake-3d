/*
 * FrameManagement.h
 *
 *  Created on: 26/09/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Events/ButtonEvents.h"
#include <iostream>

using namespace Events;
using namespace std;

ButtonEvents::ButtonEvents(){
    _device = 0;
}

ButtonEvents::ButtonEvents(irr::IrrlichtDevice *__device){
	_device = __device;
}

void ButtonEvents::handler(int __idEvent){
	cout << "ID: " << __idEvent << endl;

	switch(__idEvent){


		/*
		 * Start Main Menu Options
		 */

		case GUI_ID_CREATE_GAME_BUTTON:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiNewGame.xml", 0);
        	break;

        case GUI_ID_LOAD_GAME_BUTTON:
        	_device->getGUIEnvironment()->addFileOpenDialog(L"Selecione um jogo salvo", true, 0, 400);
        	break;

        case GUI_ID_SCORE_BUTTON:
        case GUI_ID_HELP_GAME:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiError.xml", 0);
        	break;

        case GUI_ID_PREF_BUTTON:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("xmlgui/guiPref.xml", 0);
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
        	_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiError.xml",0);
			break;

        case GUI_ID_SAVE_TYPE_GAME:
        	_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiError.xml",0);
			break;

        case GUI_ID_SAVE_CURRENT_GAME:
        	_device->getGUIEnvironment()->clear();
			_device->getGUIEnvironment()->loadGUI("xmlgui/guiError.xml",0);
			break;

		/*
		 * End File Record/Read Options
		 */

	}
}
