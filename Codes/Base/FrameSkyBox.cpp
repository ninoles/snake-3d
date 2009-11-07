#include "../../Headers/Base/FrameSkyBox.h"

using namespace base;

FrameSkyBox::FrameSkyBox(irr::scene::ISceneNode* __skyBox){
    _skyBox = __skyBox;
}

void FrameSkyBox::setSkyBox(irr::scene::ISceneNode* __skyBox){
    _skyBox = __skyBox;
}

irr::scene::ISceneNode* FrameSkyBox::getSkyBox(){
    return _skyBox;
}

