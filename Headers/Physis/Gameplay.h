/*
 * Gameplay.h
 *
 *  Created on: 19/11/2009
 *      Author: Henrique Jonas
 */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Base/FrameAnimatedNode.h"

#include <Newton.h>
#include <irrlicht.h>

#define NUMBER_CONTACTS 3
#define CONTACTS (3*NUMBER_CONTACTS)
#define NORMALS (3*NUMBER_CONTACTS)

typedef float contacts[CONTACTS];
typedef float normals[NORMALS];
typedef float penetration[NUMBER_CONTACTS];

namespace physis{

	class Gameplay{

		private:

			NewtonWorld *_newtonW;
			irr::scene::ISceneManager *_sceneManagement;

		public:

			Gameplay();
			Gameplay(irr::scene::ISceneManager *__sceneManagement);

			NewtonWorld* getNewtonWorld();

			bool checkForCollisions(base::FrameAnimatedNode* __nodeA, base::FrameAnimatedNode* __nodeB);

	};

}

#endif /* GAMEPLAY_H_ */
