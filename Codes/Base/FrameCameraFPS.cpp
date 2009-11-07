#include "../../Headers/Base/FrameCameraFPS.h"

using namespace base;

FrameCameraFPS::FrameCameraFPS(irr::scene::ISceneNodeAnimatorCameraFPS* __cameraFPS){
    _cameraFPS = __cameraFPS;
}

void FrameCameraFPS::setCameraFPS(irr::scene::ISceneNodeAnimatorCameraFPS* __cameraFPS){
    _cameraFPS = __cameraFPS;
}

irr::scene::ISceneNodeAnimatorCameraFPS* FrameCameraFPS::getCameraFPS(){
    return _cameraFPS;
}
