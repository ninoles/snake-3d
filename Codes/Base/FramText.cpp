#include "../../Headers/Base/FrameText.h"

using namespace base;

FrameText::FrameText(irr::gui::IGUIStaticText* __text){
    _text = __text;
}

void FrameText::setText(irr::gui::IGUIStaticText* __text){
    _text = __text;
}

irr::gui::IGUIStaticText* FrameText::getText(){
    return _text;
}
