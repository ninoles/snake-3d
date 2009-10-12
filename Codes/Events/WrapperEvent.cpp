#include "../../Headers/Events/WrapperEvent.h"
#include <iostream>

using namespace std;
using namespace Events;

WrapperEvents::WrapperEvents(irr::IrrlichtDevice* __device){
	_device = __device;
}

void WrapperEvents::setAllEvents(){

	_eventButton = new ButtonEvents(_device);
	_eventMenu = new MenuEvents(_device);
	_eventNode = new NodeMoviment(_device);

}

bool WrapperEvents::OnEvent(const irr::SEvent& event){

	if(event.EventType == irr::EET_GUI_EVENT){
		irr::s32 idEvent = event.GUIEvent.Caller->getID();

		switch(event.GUIEvent.EventType){
			case irr::gui::EGET_BUTTON_CLICKED:
				_eventButton->handler(idEvent);
				break;

			case irr::gui::EGET_MENU_ITEM_SELECTED:
				_eventMenu->handler(idEvent);
				break;
		}
	} else if(event.EventType == irr::EET_KEY_INPUT_EVENT)
		_eventNode->runMovement(event.KeyInput.Key);


    return false;
}
