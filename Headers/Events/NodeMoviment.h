/*
 * File:   NodeMoviment.h
 * Author: Henrique Jonas
 * Version: 0.1
 * Created on 29 de Setembro de 2009, 20:07
 */

#ifndef _NODEMOVIMENT_H
#define	_NODEMOVIMENT_H

#include <irrlicht.h>

#include "../Base/FrameAnimatedNode.h"

#define NUMBER_OF_MOVIMENTS 2

namespace Events{
    class NodeMoviment {

        private:

			int _movimentOne;
            int _movimentTwo;

            irr::f32 _movimentSpeed;

        public:

            static irr::EKEY_CODE _currentMoviment;

            NodeMoviment(irr::IrrlichtDevice *__device);
            NodeMoviment();

            void changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey, int __idNode);
            void setMovementSpeed(irr::f32 __movementSpeed);
            void verifyKey(irr::EKEY_CODE __keyPressed);

            static void setCurrentKey(irr::EKEY_CODE __key);
    };
}

#endif	/* _NODEMOVIMENT_H */

