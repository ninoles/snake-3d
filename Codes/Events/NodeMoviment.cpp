#include <iostream>

#include "../../Headers/Events/NodeMoviment.h"

using namespace Events;

NodeMoviment::NodeMoviment(irr::IrrlichtDevice *__device){
    _device = __device;

    _nodes = new GenericList::ArrayList<base::FrameSceneNode*>();
    _keys = new GenericList::ArrayList<int*>();
}

NodeMoviment::NodeMoviment(){

}

void NodeMoviment::insertKeysFromNode(int __idNode, irr::EKEY_CODE __movimentOne, irr::EKEY_CODE __movimentTwo, irr::EKEY_CODE __movimentThree, irr::EKEY_CODE __movimentFour){

	int index;

	for(index = 0;index < _nodes->getSize(); k++)
		if(_nodes->get(index)->getId() == __idNode)
			break;

	int *nMoviments[NUMBER_OF_MOVIMENTS];
	nMoviments[0] = __movimentOne;
	nMoviments[1] = __movimentTwo;
	nMoviments[2] = __movimentThree;
	nMoviments[3] = __movimentFour;

	_keys->add(nMoviments);

}

void NodeMoviment::insertNode(base::FrameSceneNode *__node){
	_nodes->add(__node);
}

void NodeMoviment::changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey, int __idNode){
    if(_movimentOne == __oldKey)
        _movimentOne = __newKey;
    else if(_movimentTwo == __oldKey)
        _movimentTwo = __newKey;
    else if(_movimentThree == __oldKey)
        _movimentTwo = __newKey;
    else if(_movimentFour == __oldKey)
        _movimentTwo = __newKey;
}

void NodeMoviment::setMovementSpeed(irr::f32 __movementSpeed){
    _movimentSpeed = __movementSpeed;
}

void NodeMoviment::runMovement(irr::EKEY_CODE __keyPressed){
    if(__keyPressed != _movimentOne && __keyPressed != _movimentTwo && __keyPressed != _movimentThree && __keyPressed != _movimentFour)
        return;

    const irr::u32 now = _device->getTimer()->getTime();

    irr::core::vector3df nodePosition = _node->getPosition(); //Pega a posícao atual do objeto na tela

    //std::cout << "Frame Rate: " << frameDeltaTime << std::endl;
    //std::cout << "Position Y: " << nodePosition.Y << std::endl;

    if(__keyPressed == _movimentOne)       //Movimenta-se sobre o eixo Y -> Para frente
        nodePosition.Y += _movimentSpeed * (now/100000.f);
    if(__keyPressed == _movimentTwo)        //Movimenta-se sobre o eixo X -> Para esquerda
        nodePosition.X += _movimentSpeed * (now/100000.f);
    if(__keyPressed == _movimentThree)      //Movimenta-se sobreo eixo X -> Para direita
        nodePosition.X -=_movimentSpeed * (now/100000.f);
    if(__keyPressed == _movimentFour)      //Movimenta-se sobreo eixo Y -> Para tras
        nodePosition.Y -=_movimentSpeed * (now/100000.f);

    _node->setPosition(nodePosition);
}

std::string NodeMoviment::toString(){
    std::cout << "Node: " << _node->getName() << ".- Moviments: " << _movimentOne << " - " << _movimentTwo
            << " - " << _movimentThree << ".- Speed: " << _movimentSpeed << ".- Device: " <<
            _device->getDebugName() << std::endl;
}


