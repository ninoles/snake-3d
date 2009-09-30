/* 
 * File:   NodeMoviment.h
 * Author: Henrique Jonas
 * Version: 0.1 BETA
 * Created on 29 de Setembro de 2009, 20:07
 */

#ifndef _NODEMOVIMENT_H
#define	_NODEMOVIMENT_H

#include <string>
#include "KeyBoardEvents.h"
#include "SAppContext.h"

namespace Events{
    class NodeMoviment {

        private:

            irr::EKEY_CODE _movimentOne;
            irr::EKEY_CODE _movimentTwo;
            irr::EKEY_CODE _movimentThree;

            irr::scene::ISceneNode *_node;
            Context::SAppContext *_context;

            irr::f32 _movimentSpeed;
            irr::u32 then;

            KeyBoardEvents _event;

        public:

            NodeMoviment(Context::SAppContext *__context);
            void setNode(irr::scene::ISceneNode *__node);
            void setKeys(irr::EKEY_CODE __movimentOne, irr::EKEY_CODE __movimentTwo, irr::EKEY_CODE __movimentThree);
            void changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey);
            void setMovementSpeed(irr::f32 __movementSpeed);
            void runMovement(irr::EKEY_CODE __keyPressed);
            std::string toString();
    };
}

#endif	/* _NODEMOVIMENT_H */

