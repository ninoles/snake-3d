#include "../../Headers/Events/ButtonEvents.h"

using namespace Events;

ButtonEvents::ButtonEvents(){
    _context = new Context::SAppContext;
}

ButtonEvents::ButtonEvents(Context::SAppContext* __context){
    _context = __context;
}

void ButtonEvents::handler(int __idEvent){
    switch(__idEvent){
        case GUI_ID_CONT_GAME:
            break;
        case GUI_ID_CREATE_GAME_BUTTON:
            break;
        case GUI_ID_LOAD_GAME_BUTTON:
            break;
        case GUI_ID_START_BUTTON:
            break;
    }
}