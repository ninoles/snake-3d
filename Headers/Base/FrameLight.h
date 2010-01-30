/*
 * Point.h
 *
 *  Created on: 29/12/2009
 *      Author: Henrique Jonas
 */

#ifndef FRAME_LIGHT_H_
#define FRAME_LIGHT_H_

#include <irrlicht.h>
#include <Newton.h>

#include "SceneObjects.h"
#include "../Physis/PhysisNode.h"

namespace base{

	class FrameLight : public base::SceneObjects{

		private:

			irr::scene::ILightSceneNode *_light;


		public:

			//Constructor
			FrameLight(NewtonWorld *__newtonW, irr::scene::ISceneManager *_sceneManager, int __id);

			FrameLight(NewtonWorld *__newtonW, irr::scene::ISceneManager *_sceneManager, int __id,
					irr::core::vector3df __position, irr::video::SColorf __color, irr::f32 __radius);

			//Main Methods
			void createLight(irr::core::vector3df __position, irr::video::SColorf __color, irr::f32 __radius);
			void repaint();
			void drop();

			//Getters
			irr::scene::ILightSceneNode* getLightSceneNode();
			irr::scene::ISceneNode *getSceneNode();
			irr::scene::IMesh* getMesh();

			//Light Methods
			void enableCastShadow(bool __enable);
			void setLightData(irr::video::SLight __color);
			void setLightType(irr::video::E_LIGHT_TYPE __type);
			void setVisible(bool __visible);
			void setRadius(irr::f32 __radius);
	};

}

#endif /* FRAME_LIGHT_H_ */
