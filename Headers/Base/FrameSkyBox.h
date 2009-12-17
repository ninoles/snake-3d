/* 
 * File:   FrameSkyBox.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 15:01
 */

#ifndef _FRAMESKYBOX_H
#define	_FRAMESKYBOX_H

#include <irrlicht.h>

#include "SceneObjects.h"

namespace base{

    class FrameSkyBox : public SceneObjects{

        private:

            irr::scene::ISceneNode *_skyBox;

        public:

            FrameSkyBox(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id);

            FrameSkyBox(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id, irr::video::ITexture* __textureUp,
            		irr::video::ITexture* __textureDown, irr::video::ITexture* __textureLeft,
            		irr::video::ITexture* __textureRight, irr::video::ITexture* __textureFt,
            		irr::video::ITexture* __textureBk, irr::scene::ISceneNode *__parent);

			//Main Methods
			void createNode( irr::video::ITexture* __textureUp,
					irr::video::ITexture* __textureDown, irr::video::ITexture* __textureLeft,
					irr::video::ITexture* __textureRight, irr::video::ITexture* __textureFt,
					irr::video::ITexture* __textureBk, irr::scene::ISceneNode *__parent);

			void repaint();
			void drop();
			void createCollision();

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

			//Getters
			irr::scene::ISceneNode* getSkyBox();
			irr::scene::IMesh* getMesh();
    };
}

#endif	/* _FRAMESKYBOX_H */
