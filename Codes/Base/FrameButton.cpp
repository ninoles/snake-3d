#include "../../Headers/Base/FrameButton.h"

using namespace base;

FrameButton::FrameButton(irr::gui::IGUIButton* __button){
    _button = __button;
}

void FrameButton::setFrameButton(irr::gui::IGUIButton* __button){
    _button = __button;
}

irr::gui::IGUIButton* FrameButton::getFrameButton(){
    return _button;
}
