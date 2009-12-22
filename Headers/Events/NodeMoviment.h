/*
 * File:   NodeMoviment.h
 * Author: Henrique Jonas
 * Version: 0.1
 * Created on 29 de Setembro de 2009, 20:07
 */

#ifndef _NODEMOVIMENT_H
#define	_NODEMOVIMENT_H

#include <irrlicht.h>

#include "../GenericList/ArrayList.h"
#include "../Base/FrameAnimatedNode.h"

#define NUMBER_OF_MOVIMENTS 2

namespace Events{
    class NodeMoviment {

        private:

            int _movimentOne;
            int _movimentTwo;

            irr::IrrlichtDevice *_device;

            GenericList::ArrayList<int> _keys;
            GenericList::ArrayList<base::FrameAnimatedNode*> *_nodes;

            irr::f32 _movimentSpeed;

        public:

            NodeMoviment(irr::IrrlichtDevice *__device);
            NodeMoviment();

            void insertMovimentNode(base::FrameAnimatedNode *__node, irr::EKEY_CODE __moviments[NUMBER_OF_MOVIMENTS]);
            void changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey, int __idNode);
            void setMovementSpeed(irr::f32 __movementSpeed);
            void runMovement(irr::EKEY_CODE __keyPressed);
    };
}

#include "../../Codes/GenericList/ArrayList.cpp"

#endif	/* _NODEMOVIMENT_H */

