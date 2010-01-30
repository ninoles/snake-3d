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
#include "../Base/FrameCameraFPS.h"

#include <irrlicht.h>
#include <Newton.h>
#include <math.h>

#define FACTOR_FORWARD_SNAKE 0.1
#define FACTOR_TURN_SNAKE  	 0.4
#define DEGRESS_TURN 	     90

#define FACTOR_RANGE_MESH 	 0.3

#define MAX_TAM_SNAKE 20

#define MAX_TURNS 10

namespace platform{

    class Snake{

		private:

			GenericList::ArrayList<base::FrameAnimatedNode*> *_nodes;
			base::FrameAnimatedNode *_head;
			base::FrameAnimatedNode *_tail;
			base::FrameAnimatedNode _node[MAX_TAM_SNAKE];

			base::FrameCameraFPS *_cameraSnake;

			irr::core::vector3df _absolutePositionFromHead;
			irr::scene::ISceneManager *_sceneManager;

			irr::EKEY_CODE _leftMoviment;
			irr::EKEY_CODE _rightMoviment;

			int _counterBreak[MAX_TURNS];
			int _indexCounterBreak;
			base::directions _directions[MAX_TURNS];

			void adjustNodes(irr::core::vector3df __newPositionFromLastNode, bool __adjust);
			void adjustNodes(int __numberNodes, bool __adjust);
			void renderSnake();
			void renderCamera();
			void adjustCounter();

			void turnBodyLeft(int __factorRotation);
			void turnBodyRight(int __factorRotation);
			void incrementCounters();

			bool isBreakEnd();


		public:

			Snake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW);
			Snake();

			void createSnake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW);
			void insertNode();
			void insertMoviment(int __idPlayer);
			void snakeForward();
			void turnLeft();
			void turnRight();
			void reposition(bool __moviment);
			void repaintSnake();
			void repaintCamera();
			void deleteNodes(int __numberNodes);

			irr::EKEY_CODE getMovimentLeft();
			irr::EKEY_CODE getMovimentRight();
			base::FrameAnimatedNode *getHead();
			base::FrameCameraFPS *getCamera();

    };
}

#endif // SNAKE_H_INCLUDED
