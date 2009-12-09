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
			NewtonWorld *_newtonWorld;

		public:

			PhysisNode(NewtonWorld *__newtonWorld);
			PhysisNode();

			void createCollisionFromMesh(NewtonWorld *__newtonWorld);

			void setNode(irr::scene::ISceneNode *__node, int __id);

			void createBody();
			void setMassAndInertia(dFloat __mass, dFloat __Ixx, dFloat __Iyy, dFloat __Izz);

	};
}

#endif /* PHYSISNODE_H_ */
