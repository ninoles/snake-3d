#include "../../Headers/Events/ButtonEvents.h"

using namespace Events;

ButtonEvents::ButtonEvents(){
    _device = 0;
}

ButtonEvents::ButtonEvents(irr::IrrlichtDevice *__device){
	_device = __device;
}

void ButtonEvents::handler(int __idEvent){
    switch(__idEvent){
        case GUI_ID_CREATE_GAME_BUTTON:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("guiNewGame.xml", 0);
        	break;
        case GUI_ID_LOAD_GAME_BUTTON:
        	_device->getGUIEnvironment()->clear();
            break;
        case GUI_ID_SCORE_BUTTON:
        	_device->getGUIEnvironment()->clear();
            break;
        case GUI_ID_PREF_BUTTON:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("guiPref.xml", 0);
        	break;
        case GUI_ID_HELP_GAME:
        	_device->getGUIEnvironment()->clear();
        	break;
        case GUI_ID_MAIN_MENU_GAME:
        	_device->getGUIEnvironment()->clear();
        	_device->getGUIEnvironment()->loadGUI("guiMainMenu.xml",0);
        	break;
        case GUI_ID_QUIT_GAME:
        	_device->closeDevice();
        	break;
    }
}
