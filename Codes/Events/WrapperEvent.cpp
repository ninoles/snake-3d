#include "../../Headers/Events/WrapperEvent.h"

using namespace Events;

WrapperEvents::WrapperEvents(){

}

void WrapperEvents::setDevice(irr::IrrlichtDevice* __device){
	_device = __device;
}

void WrapperEvents::setAllEvents(){

	_eventButton = new ButtonEvents(_device);
	_eventMenu = new MenuEvents(_device);
	_eventNode = new NodeMoviment(_device);

}

bool WrapperEvents::OnEvent(const irr::SEvent& event){
    irr::s32 idEvent = event.GUIEvent.Caller->getID();

    if(event.EventType == irr::EET_KEY_INPUT_EVENT)
        _eventNode->runMovement(event.KeyInput.Key);
    else
        switch(event.GUIEvent.EventType){
            case irr::gui::EGET_BUTTON_CLICKED:
                _eventButton->handler(idEvent);
                break;

            case irr::gui::EGET_MENU_ITEM_SELECTED:
                _eventMenu->handler(idEvent);
                break;
        }

    return false;
}
