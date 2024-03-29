#include "../../Headers/Events/MenuEvents.h"

using namespace Events;

MenuEvents::MenuEvents(irr::IrrlichtDevice *__device){
	_device = __device;
}

void MenuEvents::handler(int __idEvent){
	
	switch(__idEvent){
		case GUI_ID_PAUSE:
			break;
		
		case GUI_ID_LEAVE_GAME:
			break;
			
		case GUI_ID_BEST_PLAYERS:
			break;
		
		case GUI_ID_MATCHES:
			break;
		
		case GUI_ID_INSTRUCTIONS:
			break;
			
		case GUI_ID_ABOUT:
			break;
			
		case GUI_ID_NEW_GAME:
			break;
		
		case GUI_ID_LOAD_GAME:
			break;
		
		case GUI_ID_PREFERENCES_GAME:
			break;
		
		case GUI_ID_QUIT:
			_device->closeDevice();
			break;

		case GUI_ID_POINT_PLAYERS:
			break;
		
		case GUI_ID_WIN_PLAYERS:
			break;
	}
}
