#include <iostream>

#include "../../Headers/Events/NodeMoviment.h"

using namespace Events;

NodeMoviment::NodeMoviment(irr::IrrlichtDevice *__device){
    _device = __device;

    _nodes = new GenericList::ArrayList<base::FrameSceneNode*>();
}

NodeMoviment::NodeMoviment(){

}

void NodeMoviment::insertKeysFromNode(int __idNode, irr::EKEY_CODE __movimentOne, irr::EKEY_CODE __movimentTwo, irr::EKEY_CODE __movimentThree, irr::EKEY_CODE __movimentFour){

	int index = -1;

	for(int k = 0;k < _nodes->getSize(); k++)
		if(_nodes->get(k)->getId() == __idNode)
			index = k;

	if(index == -1)
		return;

	_keys.add(__movimentOne);
	_keys.add(__movimentTwo);
	_keys.add(__movimentThree);
	_keys.add(__movimentFour);
}

void NodeMoviment::insertNode(base::FrameSceneNode *__node){
	_nodes->add(__node);
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
				_movimentThree = _keys.get(i+2);
				_movimentFour = _keys.get(i+3);

			}
		}
	}

    //std::cout << "Movimento Quatro: " << _movimentFour << endl;
    //std::cout << "Movimento Um: " << _movimentOne << std::endl;
    //std::cout << "Tecla pressionada: " << __keyPressed << std::endl;
    //std::cout << "Index: " << index << std::endl;

	if(index == -1)
    	return;

    const irr::u32 now = _device->getTimer()->getTime();

    irr::scene::ISceneNode *node = _nodes->get(index)->getSceneNode();
    irr::core::vector3df nodePosition = node->getPosition(); //Pega a posícao atual do objeto na tela

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

    node->setPosition(nodePosition);
}
