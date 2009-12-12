	/*
 * File:   FrameCameraFPS.h
 * Author: Henrique Jonas
 *
 * Created on 3 de Outubro de 2009, 14:57
 */

#ifndef _FRAMECAMERAFPS_H
#define	_FRAMECAMERAFPS_H

#include <irrlicht.h>

#include "SceneObjects.h"

namespace base{

    class FrameCameraFPS : public SceneObjects{

        private:

            irr::scene::ICameraSceneNode *_camera;

            irr::scene::ITriangleSelector *_selector;
            irr::scene::ISceneNodeAnimator *_animCollision;

        public:

            //Constructors
            FrameCameraFPS(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id);

            FrameCameraFPS(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
                        		int __id, irr::scene::ISceneNode* __parent,
                    			irr::f32 __rotateSpeed, irr::f32 __moveSpeed, irr::SKeyMap* __keyMapArray,
                    			irr::s32 __keyMapSize, bool __noVerticalMovement,
                    			irr::f32 __jumpSpeed);

            //Main Methods
            void createCamera(irr::scene::ISceneNode* __parent,
        			irr::f32 __rotateSpeed, irr::f32 __moveSpeed, irr::SKeyMap* __keyMapArray,
        			irr::s32 __keyMapSize, bool __noVerticalMovement,
        			irr::f32 __jumpSpeed);
            void dropCamera();
            void repaint();

            //Camera Methods
            void bindTargetAndRotation(bool __bound);
            void setAspectRatio(irr::f32 __aspect);
            void setFarValue(irr::f32 __farValue);
            void setFOV(irr::f32 __fov);
            void setInputReceiverEnable(bool __enable);
            void setKeyMap(irr::SKeyMap *__map, irr::u32 __count);
            void setMoveSpeed(irr::f32 __moveSpeed);
            void setRotationSpedd(irr::f32 __rotationSpeed);
            void setVerticalMoviment(bool __verticalMov);

            irr::f32 getMoveSpeed();
            irr::f32 getRotateSpeed();

            //Getters
            irr::scene::ICameraSceneNode* getCamera();
            irr::scene::ISceneNodeAnimatorCameraFPS* getCameraFPS();

            //Interface Methods
            void createTrianguleSelector(irr::scene::ITerrainSceneNode *__terrainNodeconst, irr::core::vector3df __ellipsoidRadius,
					irr::core::vector3df __gravityPerSecond, irr::core::vector3df __ellipsoidTranslation,
					irr::f32 __slidingValue = 0.0005f);

    };
}



#endif	/* _FRAMECAMERAFPS_H */

