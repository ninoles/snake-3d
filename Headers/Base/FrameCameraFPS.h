/* 
 * File:   FrameCameraFPS.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 14:57
 */

#ifndef _FRAMECAMERAFPS_H
#define	_FRAMECAMERAFPS_H

#include <irrlicht.h>

namespace base{

    class FrameCameraFPS{

        private:

            irr::scene::ISceneNodeAnimatorCameraFPS *_cameraFPS;

        public:

            FrameCameraFPS(irr::scene::ISceneNodeAnimatorCameraFPS *__cameraFPS);

            void setCameraFPS(irr::scene::ISceneNodeAnimatorCameraFPS *__cameraFPS);
            irr::scene::ISceneNodeAnimatorCameraFPS* getCameraFPS();

    };
}



#endif	/* _FRAMECAMERAFPS_H */

