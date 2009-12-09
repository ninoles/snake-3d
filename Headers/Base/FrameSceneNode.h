/* 
 * File:   FrameSceneNode.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 13:47
 */

#ifndef _FRAMESCENENODE_H
#define	_FRAMESCENENODE_H

#include <irrlicht.h>
#include <Newton.h>

namespace base{

    class FrameSceneNode{
        private:

            irr::scene::ISceneNode *_sceneNode;

            NewtonCollision *_collision;

            signed int _id;

        public:

            FrameSceneNode();
            FrameSceneNode(irr::scene::ISceneNode *__sceneNode, signed int __id);

            void setSceneNode(irr::scene::ISceneNode *__sceneNode);
            irr::scene::ISceneNode* getSceneNode();

            void setCollisionNode(NewtonCollision *__collision);
            NewtonCollision* getCollision();

            signed int getId();

    };

}

#endif	/* _FRAMESCENENODE_H */
