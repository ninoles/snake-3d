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

#include "MeshCollision.h"

namespace physis{

	class PhysisNode{

		private:

			irr::scene::IMesh *_mesh;

			MeshCollision *_collision;
			NewtonBody *_newtonBody;
			NewtonWorld *_newtonWorld;

		public:

			PhysisNode(NewtonWorld *__newtonWorld);
			PhysisNode();

			void createCollisionFromMesh(irr::scene::IMesh *_mesh);

			void createBody();
			void setMassAndInertia(dFloat __mass, dFloat __Ixx, dFloat __Iyy, dFloat __Izz);

			MeshCollision* getMeshCollision();

	};
}

#endif /* PHYSISNODE_H_ */
