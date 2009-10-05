#include "../../Headers/Base/FrameCameraMaya.h"

using namespace base;

FrameCameraMaya::FrameCameraMaya(irr::scene::ISceneNodeAnimatorCameraMaya* __cameraMaya){
    _cameraMaya = __cameraMaya;
}

void FrameCameraMaya::setCameraMaya(irr::scene::ISceneNodeAnimatorCameraMaya* __cameraMaya){
    _cameraMaya = __cameraMaya;
}

irr::scene::ISceneNodeAnimatorCameraMaya* FrameCameraMaya::getCameraMaya(){
    return _cameraMaya;
}
