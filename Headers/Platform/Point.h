/*
 * Point.h
 *
 *  Created on: 30/12/2009
 *      Author: Henrique Jonas
 */

#ifndef POINT_H_
#define POINT_H_

#include <irrlicht.h>
#include <Newton.h>

#include "../Base/FrameAnimatedNode.h"

#define REPETITIONS 15

namespace platform{

	class Point{

		private:

			base::FrameAnimatedNode *_mesh;

			int _value;
			int _currentRepetition;

			void initComponent();

		public:

			Point(irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW, int __id);

			void insertPointInPosition(irr::core::vector3df __position);
			void setVisible(bool __visible);
			void setMaxPoints(int __maxPoints);
			int getValue();

			bool isRepetitions();

			base::FrameAnimatedNode* getAnimatedNode();
	};
}

#endif /* POINT_H_ */
