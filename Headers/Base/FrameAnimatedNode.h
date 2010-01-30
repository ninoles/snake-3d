
/* 
 * File:   FrameAnimatedNode.h
 * Author: Henrique Jonas
 *
 * Created on 3 de Outubro de 2009, 13:57
 */

#ifndef _FRAMEANIMATEDNODE_H
#define	_FRAMEANIMATEDNODE_H

#define MOVIMENTS 2

#include <irrlicht.h>
#include <Newton.h>

#include "SceneObjects.h"
#include "../Physis/PhysisNode.h"

namespace base{

	enum directions{
		NOTHING = -1,
		NORTH,
		WEST,
		SOUTH,
		EAST,
	};

    class FrameAnimatedNode : public SceneObjects{

        private:

            irr::scene::IAnimatedMeshSceneNode *_mesh;
            irr::EKEY_CODE _moviments[MOVIMENTS];

            int _indexMoviment;

            directions _direction;

        public:

            //This field has the function to tell if the mesh is colliding with another mesh.
            bool _movimentNode;

            //Constructor
            FrameAnimatedNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id);

            FrameAnimatedNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id, const irr::c8* __filename, irr::core::vector3df __rotarion, irr::core::vector3df __position,
            		irr::core::vector3df __scale);

            FrameAnimatedNode();

            void initComponent(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id);

            //Main Methods
            void createNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id,const irr::c8* __filename,  irr::core::vector3df __rotarion, irr::core::vector3df __position,
            		irr::core::vector3df __scale);
            void createNode(const irr::c8* __filename,  irr::core::vector3df __rotarion, irr::core::vector3df __position,
            		irr::core::vector3df __scale);
            void createNode(const irr::c8* __filename);
            void repaint();
            void drop();
            void createCollision();
            void insertKeyMoviment(irr::EKEY_CODE __key);
            void setDirection(directions __direction);

            //Getters
            irr::scene::IAnimatedMeshSceneNode* getAnimatedMesh();
            irr::scene::ISceneNode* getSceneNode();
            irr::scene::IMesh* getMesh();
            irr::EKEY_CODE* getKeyMoviment();
            directions getDirection();

            //Mesh Methods
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

            //Animators Methods
            irr::s32 getStartFrame();
            irr::s32 getFinalFrame();
            irr::f32 getCurrentFrame();

            void setCurrentFrame(irr::f32 __frame);
            void setFrameLoop(irr::s32 __start, irr::s32 __end);
            void setAnimationSpeed(irr::f32 __framePerSecond);

    };
};

#endif	/* _FRAMEANIMATEDNODE_H */
