#include "../../Headers/Events/KeyBoardEvents.h"

using namespace Events;

KeyBoardEvents::KeyBoardEvents(){
    for(int k = 0; k < irr::KEY_KEY_CODES_COUNT; k++)
        _keysDown[k] = false;
}

bool KeyBoardEvents::isKeyDown(irr::EKEY_CODE __keyCode){
    return _keysDown[__keyCode];
}

