/* 
 * File:   FrameCameraMaya.h
 * Author: Henrique Jonas
 *
 * Created on 3 de Outubro de 2009, 14:59
 */

#ifndef _FRAMECAMERAMAYA_H
#define	_FRAMECAMERAMAYA_H

#include <irrlicht.h>

#include "SceneObjects.h"

namespace base{
    
    class FrameCameraMaya : public SceneObjects{

        private:

            irr::scene::ICameraSceneNode *_camera;

            irr::scene::ITriangleSelector *_selector;
            irr::scene::ISceneNodeAnimator *_animCollision;

        public:

            //Constructors
            FrameCameraMaya(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id);

            FrameCameraMaya(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id, irr::scene::ISceneNode* __parent, irr::f32 __rotateSpeed,
            		irr::f32 __zoomSpeed, irr::f32 __translationSpeed);

            //Main Methods
            void createCamera(irr::scene::ISceneNode* __parent, irr::f32 __rotateSpeed,
            		irr::f32 __zoomSpeed, irr::f32 __translationSpeed);
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
            void setZoomSpeed(irr::f32 __zoomSpeed);
            void setVerticalMoviment(bool __verticalMov);

            irr::f32 getMoveSpeed();
            irr::f32 getRotateSpeed();
            irr::f32 getZooomSpeed();

            //Getters
            irr::scene::ICameraSceneNode* getCamera();
            irr::scene::ISceneNodeAnimatorCameraMaya* getCameraMaya();

            //Interface Methods
            void createTrianguleSelector(irr::scene::ITerrainSceneNode *__terrainNodeconst, irr::core::vector3df __ellipsoidRadius,
					irr::core::vector3df __gravityPerSecond, irr::core::vector3df __ellipsoidTranslation,
					irr::f32 __slidingValue);
    };
}

#endif	/* _FRAMECAMERAMAYA_H */
