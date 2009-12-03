/*
 * PhysisNode.h
 *
 *  Created on: 19/11/2009
 *      Author: henrique
 */

#ifndef PHYSISNODE_H_
#define PHYSISNODE_H_

#include <Newton.h>
#include <irrlicht.h>

#include "../Base/FrameSceneNode.h"

#include "MeshCollision.h"

#define NEWTON_TO_IRR 32.0f
#define IRR_TO_NEWTON	(1.0f / NEWTON_TO_IRR)

namespace plataform{

	class PhysisNode{

		private:

			base::FrameSceneNode *_node;

			dFload _mass;
			dFloat _inertia;

			MeshCollision *_collision;
			NewtonBody *_newtonBody;

		public:

			PhysisNode();

			void setMass(dFloat __mass);
			void setInertia(dFloat __inertia);
			void setMassMatrix(dFloat __Ixx, dFloat __Iyy, dFloat __Izz);
			void setCollisionFromMesh(NewtonWorld *__newtonWorld);

	};
}

#endif /* PHYSISNODE_H_ */
