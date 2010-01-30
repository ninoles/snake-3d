#include <iostream>

#include "../../Headers/Events/NodeMoviment.h"

using namespace Events;

irr::EKEY_CODE NodeMoviment::_currentMoviment = irr::KEY_KEY_0;

NodeMoviment::NodeMoviment(irr::IrrlichtDevice *__device){

}

NodeMoviment::NodeMoviment(){

}

void NodeMoviment::changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey, int __idNode){

}

void NodeMoviment::setMovementSpeed(irr::f32 __movementSpeed){
    _movimentSpeed = __movementSpeed;
}

void NodeMoviment::verifyKey(irr::EKEY_CODE __keyPressed){
	setCurrentKey(__keyPressed);
}

void NodeMoviment::setCurrentKey(irr::EKEY_CODE __key){
	_currentMoviment = __key;
}
