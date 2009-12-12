/*
 * SceneObjects.h
 *
 *  Created on: 10/12/2009
 *      Author: Henrique Jonas
 */

#ifndef SCENEOBJECTS_H_
#define SCENEOBJECTS_H_

#include <irrlicht.h>
#include <Newton.h>

#include "BasicObject.h"
#include "../Physis/PhysisNode.h"

namespace base{

	class SceneObjects : public BasicObject{

		protected:

			irr::scene::ISceneManager *_sceneManager;

			irr::core::vector3df _position;
			irr::core::vector3df _rotation;
			irr::core::vector3df _scale;

			physis::PhysisNode *_physicalNode;

		public:

			SceneObjects(irr::scene::ISceneManager *__sceneManager, NewtonWorld *_nWorld, void *__sceneObject, int __id);

			void setPosition(float __pX, float __pY, float __pZ);
			void setRotation(float __rX, float __rY, float __rZ);
			void setScale(float __sX, float __sY, float __sZ);

	};
}

#endif /* SCENEOBJECTS_H_ */
