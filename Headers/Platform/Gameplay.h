/*
 * Gameplay.h
 *
 *  Created on: 19/11/2009
 *      Author: Henrique Jonas
 */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Base/FrameAnimatedNode.h"
#include "Match.h"

#include <Newton.h>
#include <irrlicht.h>

//Constants for analysis of the collision between 3D models
#define NUMBER_CONTACTS 3
#define CONTACTS (3*NUMBER_CONTACTS)
#define NORMALS (3*NUMBER_CONTACTS)

typedef float contacts[CONTACTS];
typedef float normals[NORMALS];
typedef float penetration[NUMBER_CONTACTS];

namespace platform{

	class Gameplay{

		private:

			NewtonWorld *_newtonW;
			irr::scene::ISceneManager *_sceneManagement;
			irr::video::IVideoDriver *_driver;

			Match *_match;

		public:

			Gameplay(irr::scene::ISceneManager *__sceneManagement, irr::video::IVideoDriver *__driver);

			void initMatch();
			void randomMap();
			void delayPoint();

			void run();

			void checkCollisionToPoint();
			void checkForCollisions(base::FrameAnimatedNode* __nodeA, base::FrameAnimatedNode* __nodeB);

			NewtonWorld* getNewtonWorld();

	};

}

#endif /* GAMEPLAY_H_ */
