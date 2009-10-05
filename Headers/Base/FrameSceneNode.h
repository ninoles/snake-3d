/* 
 * File:   FrameSceneNode.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 13:47
 */

#ifndef _FRAMESCENENODE_H
#define	_FRAMESCENENODE_H

#include <irrlicht.h>

#include "../Events/NodeMoviment.h"

namespace base{

    class FrameSceneNode{
        private:

            Events::NodeMoviment *_movimentNode;
            irr::scene::ISceneNode *_sceneNode;


        public:

            FrameSceneNode(irr::scene::ISceneNode *__sceneNode);
            void setSceneNode(irr::scene::ISceneNode *__sceneNode);
            irr::scene::ISceneNode* getSceneNode();

            Events::NodeMoviment* getNodeMoviment();
            void setNodeMoviment(Events::NodeMoviment* __movimentNode);

    };

};



#endif	/* _FRAMESCENENODE_H */

