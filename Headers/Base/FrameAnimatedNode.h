/* 
 * File:   FrameAnimatedNode.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 13:57
 */

#ifndef _FRAMEANIMATEDNODE_H
#define	_FRAMEANIMATEDNODE_H

#include <irrlicht.h>

namespace base{

    class FrameAnimatedNode{

        private:

            irr::scene::IAnimatedMeshSceneNode *_mesh;

        public:

            FrameAnimatedNode(irr::scene::IAnimatedMeshSceneNode *__animatedNode);
            
            void setAnimatedSceneNode(irr::scene::IAnimatedMeshSceneNode *__animatedNode);
            irr::scene::IAnimatedMeshSceneNode* getAnimatedScene();

    };
};


#endif	/* _FRAMEANIMATEDNODE_H */

