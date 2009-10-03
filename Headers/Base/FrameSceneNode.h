/* 
 * File:   FrameSceneNode.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 13:47
 */

#ifndef _FRAMESCENENODE_H
#define	_FRAMESCENENODE_H

#include "../Events/NodeMoviment.h"

namespace base{

    class FrameSceneNode : public irr::scene::ISceneNode{
        private:

            Events::NodeMoviment *_movimentNode;

        public:

            Events::NodeMoviment* getNodeMoviment();
            void setNodeMoviment(Events::NodeMoviment* __movimentNode);

    };

};



#endif	/* _FRAMESCENENODE_H */

