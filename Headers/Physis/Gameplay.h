/*
 * Gameplay.h
 *
 *  Created on: 19/11/2009
 *      Author: Henrique Jonas
 */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <Newton.h>
#include <irrlicht.h>
#include <stdarg.h>

#include "../GenericList/ArrayList.h"
#include "../Base/FrameSceneNode.h"

namespace physis{

	class Gameplay{

		private:

			NewtonWorld *_newtonW;
			irr::scene::ISceneManager *_sceneManagement;

			GenericList::ArrayList<base::FrameSceneNode> *_nodes;

		public:

			Gameplay();
			Gameplay(irr::scene::ISceneManager *__sceneManagement);

			void insertFrameNode(base::FrameSceneNode __valueNode);
			bool checkForCollisions(int numberOfNodes,...);

	};

}

#include "../../Codes/GenericList/ArrayList.cpp"

#endif /* GAMEPLAY_H_ */
