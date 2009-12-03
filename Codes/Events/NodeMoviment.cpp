#include <iostream>

#include "../../Headers/Events/NodeMoviment.h"

using namespace Events;

NodeMoviment::NodeMoviment(irr::IrrlichtDevice *__device){
    _device = __device;
}

void NodeMoviment::setKeys(irr::EKEY_CODE __movimentOne, irr::EKEY_CODE __movimentTwo, irr::EKEY_CODE __movimentThree){
    _movimentOne = __movimentOne;
    _movimentTwo = __movimentTwo;
    _movimentThree = __movimentThree;
}

void NodeMoviment::setNode(irr::scene::ISceneNode* __node){
    _node = __node;
    then = _device->getTimer()->getTime();
}

void NodeMoviment::changeKey(irr::EKEY_CODE __oldKey, irr::EKEY_CODE __newKey){
    if(_movimentOne == __oldKey)
        _movimentOne = __newKey;
    else if(_movimentTwo == __oldKey)
        _movimentTwo = __newKey;
    else if(_movimentTwo == __oldKey)
        _movimentTwo = __newKey;
}

void NodeMoviment::setMovementSpeed(irr::f32 __movementSpeed){
    _movimentSpeed = __movementSpeed;
}

void NodeMoviment::runMovement(irr::EKEY_CODE __keyPressed){
    if(__keyPressed != _movimentOne && __keyPressed != _movimentTwo && __keyPressed != _movimentThree)
        return;

    const irr::u32 now = _device->getTimer()->getTime();
    then = now;

    irr::core::vector3df nodePosition = _node->getPosition(); //Pega a posícao atual do objeto na tela

    //std::cout << "Frame Rate: " << frameDeltaTime << std::endl;
    //std::cout << "Position Y: " << nodePosition.Y << std::endl;

    if(__keyPressed == _movimentOne)       //Movimenta-se sobre o eixo Y -> Para frente
        nodePosition.Y += _movimentSpeed * (then/100000.f);
    if(__keyPressed == _movimentTwo)        //Movimenta-se sobre o eixo X -> Para esquerda
        nodePosition.X += _movimentSpeed * (then/100000.f);
    if(__keyPressed == _movimentThree)      //Movimenta-se sobreo eixo X -> Para direita
        nodePosition.X -=_movimentSpeed * (then/100000.f);

    _node->setPosition(nodePosition);
}

std::string NodeMoviment::toString(){
    std::cout << "Node: " << _node->getName() << ".- Moviments: " << _movimentOne << " - " << _movimentTwo
            << " - " << _movimentThree << ".- Speed: " << _movimentSpeed << ".- Device: " <<
            _device->getDebugName() << std::endl;
}


