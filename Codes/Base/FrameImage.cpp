#include "../../Headers/Base/FrameImage.h"

using namespace base;

FrameImage::FrameImage(irr::gui::IGUIImage* __image){
    _image = __image;
}

void FrameImage::setImage(irr::gui::IGUIImage* __image){
    _image = __image;
}

irr::gui::IGUIImage* FrameImage::getImageFrame(){
    return _image;
}