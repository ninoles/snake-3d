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
            break;
        case GUI_ID_LOAD_GAME_BUTTON:
            break;
        case GUI_ID_SCORE_BUTTON:
            break;
        case GUI_ID_PREF_BUTTON:
        	break;
        case GUI_ID_HELP_GAME:
        	break;
        case GUI_ID_QUIT_GAME:
        	_device->closeDevice();
        	break;
    }
}
