/*
 * Snake.h
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "../GenericList/ArrayList.h"
#include "../Base/FrameAnimatedNode.h"

#include <irrlicht.h>
#include <Newton.h>

#define FACTOR_FORWARD_SNAKE 0.9
#define FACTOR_1_TURN_SNAKE  0.4
#define FACTOR_2_TURN_SNAKE  0.75

#define FACTOR_RANGE_MESH 10.75

namespace platform{

    class Snake{

		private:

			GenericList::ArrayList<base::FrameAnimatedNode*> *_nodes;
			base::FrameAnimatedNode *_head;
			base::FrameAnimatedNode *_tail;
			base::FrameAnimatedNode *_node;

			irr::core::vector3df _absolutePositionFromHead;
			irr::scene::ISceneManager *_sceneManager;

			void adjustNodes(irr::core::vector3df __newPositionFromLastNode, bool __adjust);
			void adjustNodes(int __numberNodes, bool __adjust);
			void renderSnake();

		public:

			Snake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW);

			void insertNode();
			void snakeForward();
			void turnLeft(irr::core::vector3df __newPosition);
			void turnRight(irr::core::vector3df __newPosition);
			void repaintSnake();
			void deleteNodes(int __numberNodes);

			irr::EKEY_CODE* getHeadMoviments();
			base::FrameAnimatedNode *getHead();

    };
}

#include "../../Codes/GenericList/ArrayList.cpp"

#endif // SNAKE_H_INCLUDED
