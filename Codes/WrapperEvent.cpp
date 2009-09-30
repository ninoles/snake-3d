#include "../Headers/WrapperEvent.h"

using namespace Events;

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