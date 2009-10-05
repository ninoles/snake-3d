#include "../../Headers/Base/FrameFont.h"

using namespace base;

FrameFont::FrameFont(irr::gui::IGUIFont* __font){
    _font = __font;
}

void FrameFont::setFont(irr::gui::IGUIFont* __font){
    _font = __font;
}

irr::gui::IGUIFont* FrameFont::getFont(){
    return _font;
}
