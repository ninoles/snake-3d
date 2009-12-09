/*
 * MeshCollision.h
 *
 *  Created on: 19/11/2009
 *      Author: henrique
 */

#ifndef MESHCOLLISION_H_
#define MESHCOLLISION_H_

#include <Newton.h>
#include <irrlicht.h>

#include "../Base/FrameSceneNode.h"

namespace physis{
	class MeshCollision{

		private:

			base::FrameSceneNode *_node;

			NewtonWorld *_nWorld;
			NewtonCollision *_newtonCol;

			float *_vertices;
			irr::scene::IMeshBuffer *_meshBuffer;

			irr::u32 getVerticesFromMesh();
			void copyToMeshBuffer();

		public:

			MeshCollision(NewtonWorld *__nWorld, base::FrameSceneNode *__node);
			~MeshCollision();

			void createCollision();

			NewtonCollision* getCollisionNode();
	};
};


#endif /* MESHCOLLISION_H_ */
