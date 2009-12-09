/* 
 * File:   NodeMoviment.h
 * Author: Henrique Jonas
 * Version: 0.1
 * Created on 29 de Setembro de 2009, 20:07
 */

#ifndef _NODEMOVIMENT_H
#define	_NODEMOVIMENT_H

#include <string>

#include "KeyBoardEvents.h"

#include "../GenericList/ArrayList.h"
#include "../Base/FrameSceneNode.h"

#define NUMBER_OF_MOVIMENTS 4

namespace Events{
    class NodeMoviment {

        private:

            irr::EKEY_CODE _movimentOne;
            irr::EKEY_CODE _movimentTwo;
            irr::EKEY_CODE _movimentThree;
            irr::EKEY_CODE _movimentFour;

            irr::IrrlichtDevice *_device;

            GenericList::ArrayList<int*> *_keys;
            GenericList::ArrayList<base::FrameSceneNode*> *_nodes;

            irr::f32 _movimentSpeed;

            KeyBoardEvents _event;

        public:

            NodeMoviment(irr::IrrlichtDevice *__device);
            NodeMoviment();

            void insertNode(base::FrameSceneNode *__node);
            void insertKeysFromNode(int __idNode, irr::EKEY_CODE __movimentOne, irr::EKEY_CODE __movimentTwo, irr::EKEY_CODE __movimentThree, irr::EKEY_CODE __movimentFour);
            void changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey, int __idNode);
            void setMovementSpeed(irr::f32 __movementSpeed);
            void runMovement(irr::EKEY_CODE __keyPressed);
            std::string toString();
    };
}

#endif	/* _NODEMOVIMENT_H */

