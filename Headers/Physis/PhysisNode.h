/*
 * PhysisNode.h
 *
 *  Created on: 19/11/2009
 *      Author: Henrique Jonas
 */

#ifndef PHYSISNODE_H_
#define PHYSISNODE_H_

#include <Newton.h>
#include <irrlicht.h>

#include "../Base/FrameSceneNode.h"

#include "MeshCollision.h"

namespace physis{

	class PhysisNode{

		private:

			base::FrameSceneNode *_node;

			MeshCollision *_collision;
			NewtonBody *_newtonBody;

		public:

			PhysisNode();

			void setCollisionFromMesh(NewtonWorld *__newtonWorld);

			void setNode(irr::scene::ISceneNode *__node, int __id);
			void setBody(NewtonBody *__body);
	};
}

#endif /* PHYSISNODE_H_ */
