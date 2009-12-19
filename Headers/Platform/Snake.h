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

namespace platform{

    class Snake{

		private:

			GenericList::ArrayList<base::FrameAnimatedNode> _nodes;
			base::FrameAnimatedNode *_head;
			base::FrameAnimatedNode *_tail;

			irr::core::vector3df __absolutePositionFromHead;
			irr::scene::ISceneManager *_sceneManager;

			void adjustNodes(irr::core::vector3df __newPositionFromHead);
			void adjustNodes(int __numberNodes);

		public:

			Snake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager);

			void insertNode();
			void deleteNodes(int __numberNodes);
			void renderSnake();

    };
}

#endif // SNAKE_H_INCLUDED
