#include <iostream>

#include "../../Headers/Events/NodeMoviment.h"

using namespace Events;

NodeMoviment::NodeMoviment(irr::IrrlichtDevice *__device){
    _device = __device;

    _nodes = new GenericList::ArrayList<base::FrameAnimatedNode*>();
}

NodeMoviment::NodeMoviment(){

}

void NodeMoviment::insertMovimentNode(base::FrameAnimatedNode *__node, irr::EKEY_CODE __moviments[NUMBER_OF_MOVIMENTS]){
	_nodes->add(__node);

	_keys.add(__moviments[0]);
	_keys.add(__moviments[1]);
}

void NodeMoviment::changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey, int __idNode){

}

void NodeMoviment::setMovementSpeed(irr::f32 __movementSpeed){
    _movimentSpeed = __movementSpeed;
}

void NodeMoviment::runMovement(irr::EKEY_CODE __keyPressed){

    int index = -1;
    int numberMoviments = NUMBER_OF_MOVIMENTS;

	for(int i = 0, j = 0; i < _keys.getSize(); i+=4, j++, numberMoviments *= 2){
		for(int k = i; k < numberMoviments; k++){
			if(_keys.get(k) == __keyPressed){
				index = j;

				_movimentOne = _keys.get(i);
				_movimentTwo = _keys.get(i+1);
			}
		}
	}

	if(index == -1)
    	return;

    //Condition of collision node
    if(!_nodes->get(index)->_movimentNode)
    	return;

    irr::core::vector3df nodeRotation = _nodes->get(index)->getRotation();

    const irr::u32 now = _device->getTimer()->getTime();

    if(__keyPressed == _movimentOne)
        nodeRotation.Y -= _movimentSpeed  * (now/100000.f);
    if(__keyPressed == _movimentTwo)
        nodeRotation.Y +=_movimentSpeed  * (now/100000.f);

    _nodes->get(index)->setRotation(nodeRotation.X, nodeRotation.Y, nodeRotation.Z);
    _nodes->get(index)->repaint();
}
