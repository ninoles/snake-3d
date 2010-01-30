/*
 * FrameTerrainSceneNode.h
 *
 *  Created on: 10/12/2009
 *      Author: henrique
 */

#ifndef FRAMETERRAINSCENENODE_H_
#define FRAMETERRAINSCENENODE_H_

#include <irrlicht.h>

#include "SceneObjects.h"

namespace base{

	class FrameTerrainSceneNode :  public SceneObjects{

		private:

			irr::scene::ITerrainSceneNode *_terrainNode;

		public:

			//Constructors
			FrameTerrainSceneNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
					int __id);

			FrameTerrainSceneNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
					int __id, const irr::c8* __filename, irr::scene::ISceneNode *__parent,
					irr::video::SColor __vertexColor, irr::s32 __maxLOD,
					irr::scene::E_TERRAIN_PATCH_SIZE __patchSize, irr::s32 __smoothFactor);

			//Main Methods
			void createTerrain(const irr::c8* __filename, irr::scene::ISceneNode *__parent,
					irr::video::SColor __vertexColor, irr::s32 __maxLOD,
					irr::scene::E_TERRAIN_PATCH_SIZE __patchSize, irr::s32 __smoothFactor);
			void drop();
			void repaint();
			void createCollision();

			//TerrainNode Methods
			void scaleTexture(irr::f32 __scale, irr::f32 __scaleTwo);
			void setCameraMovimentDelta(irr::f32 __delta);
			void setCameraRotationDelta(irr::f32 __delta);
			void setDynamicSelectorUpdate(bool __update);
			void setLODOfPatch(irr::s32 __patchX, irr::s32 __patchZ, irr::s32 __LOD);

			irr::core::aabbox3d<irr::f32> getBoundingBox();
			irr::f32 getHeight(irr::f32 __pX, irr::f32 __pY);
			irr::u32 getIndexCount();
			irr::core::vector3df getTerrainCenter();

			//SceneNode Methods
			void setMaterialFlag(irr::video::E_MATERIAL_FLAG __flag, bool __newvalue);
			void setTexture(irr::u32 __textureLayer, irr::video::ITexture *__texture);
			void setMaterialType(irr::video::E_MATERIAL_TYPE __newType);
			void setVisible(bool __visible);
			void updateAbsolutePosition();

			irr::core::aabbox3d<irr::f32> getTranformedBoundingBox();
			irr::core::matrix4 getRelativeTranformation();
			irr::core::vector3df getAbsolutePosition();
			irr::scene::ESCENE_NODE_TYPE getType();
			irr::scene::ISceneNode* getParent();

			//Getters
			irr::scene::ITerrainSceneNode* getTerrainNode();
			irr::scene::ISceneNode* getSceneNode();
			irr::scene::IMesh* getMesh();

	};
}


#endif /* FRAMETERRAINSCENENODE_H_ */
