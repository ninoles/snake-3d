/*
 * Snake.cpp
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Snake.h"

platform::Snake::Snake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW){
	_nodes = new GenericList::ArrayList<base::FrameAnimatedNode*>();
	_sceneManager = __sceneManager;
	_absolutePositionFromHead = __initialPosition;

	_head = new base::FrameAnimatedNode(__newtonW, __sceneManager, 0);
	_tail = new base::FrameAnimatedNode(__newtonW, __sceneManager, 1);
	_node = new base::FrameAnimatedNode(__newtonW, __sceneManager, 2);

	_nodes->add(_node);

	renderSnake();

	_head->createCollision();
	_tail->createCollision();
	_node->createCollision();
}

platform::Snake::Snake(){
	_nodes = new GenericList::ArrayList<base::FrameAnimatedNode*>();
}

void platform::Snake::createSnake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW){
	_sceneManager = __sceneManager;
	_absolutePositionFromHead = __initialPosition;

	_head = new base::FrameAnimatedNode(__newtonW, __sceneManager, 0);
	_tail = new base::FrameAnimatedNode(__newtonW, __sceneManager, 1);
	_node = new base::FrameAnimatedNode(__newtonW, __sceneManager, 2);

	_nodes->add(_node);

	renderSnake();

	_head->createCollision();
	_tail->createCollision();
	_node->createCollision();
}

//False -> Move the tail back
//True -> Move the tail front
void platform::Snake::adjustNodes(irr::core::vector3df __newPositionFromLastNode, bool __adjust){
	if(__adjust){
		_nodes->get(_nodes->getSize()-1)->setPosition(__newPositionFromLastNode.X + FACTOR_RANGE_MESH, __newPositionFromLastNode.Y, __newPositionFromLastNode.Z);
		_tail->setPosition(__newPositionFromLastNode.X + (2*FACTOR_RANGE_MESH), _tail->getPosition().Y, _tail->getPosition().Z);
	} else {
		_tail->setPosition(__newPositionFromLastNode.X + FACTOR_RANGE_MESH, _tail->getPosition().Y, _tail->getPosition().Z);
	}
}

//False -> Insert Node
//True -> Remove Nodes
void platform::Snake::adjustNodes(int __numberNodes, bool __adjust){
	if(__adjust){
		for(int k = __numberNodes; k > 1 && k <= _nodes->getSize(); k--)
			_nodes->remove(k);

		adjustNodes(_nodes->get(_nodes->getSize()-1)->getPosition(), __adjust);
	} else {
		_nodes->add(_node);
		adjustNodes(_nodes->get(_nodes->getSize()-2)->getPosition(), __adjust);
	}

	repaintSnake();
}

void platform::Snake::turnLeft(irr::core::vector3df __newPosition){

	float pY = 0;

	_node->setRotation(_node->getRotation().X, _node->getRotation().Y - (__newPosition.Y/FACTOR_1_TURN_SNAKE), _node->getRotation().Z);
	pY = _node->getRotation().Y;

	if(_nodes->getSize() != 0){
		for(int k = 0; k < _nodes->getSize(); k++){
			_nodes->get(k)->setRotation(_nodes->get(k)->getRotation().X,_nodes->get(k)->getRotation().Y - (pY/FACTOR_2_TURN_SNAKE),_nodes->get(k)->getRotation().Z);
			pY = _nodes->get(k)->getRotation().Y;
		}
	}

	_tail->setRotation(_tail->getRotation().X, _tail->getRotation().Y - (pY/FACTOR_2_TURN_SNAKE), _tail->getRotation().Z);

	repaintSnake();
}

void platform::Snake::turnRight(irr::core::vector3df __newPosition){

	float pY = 0;

	_node->setRotation(_node->getRotation().X, _node->getRotation().Y + (__newPosition.Y/FACTOR_1_TURN_SNAKE), _node->getRotation().Z);
	pY = _node->getRotation().Y;

	if(_nodes->getSize() != 0){
		for(int k = 0; k < _nodes->getSize(); k++){
			_nodes->get(k)->setRotation(_nodes->get(k)->getRotation().X,_nodes->get(k)->getRotation().Y + (pY/FACTOR_2_TURN_SNAKE),_nodes->get(k)->getRotation().Z);
			pY = _nodes->get(k)->getRotation().Y;
		}
	}

	_tail->setRotation(_tail->getRotation().X, _tail->getRotation().Y + (pY/FACTOR_2_TURN_SNAKE), _tail->getRotation().Z);

	repaintSnake();
}

void platform::Snake::insertNode(){
	adjustNodes(1, true);
}

void platform::Snake::insertMoviment(int __idPlayer){

	if(__idPlayer == 1 && _head->getKeyMoviment() == 0){
		_head->insertKeyMoviment(irr::KEY_KEY_A);
		_head->insertKeyMoviment(irr::KEY_KEY_D);

	} else if(__idPlayer == 2 && _head->getKeyMoviment() == 0){
		_head->insertKeyMoviment(irr::KEY_LEFT);
		_head->insertKeyMoviment(irr::KEY_RIGHT);
	}

}

void platform::Snake::snakeForward(){
	_head->setPosition(_head->getPosition().X+FACTOR_FORWARD_SNAKE, _head->getPosition().Y, _head->getPosition().Z);

	irr::core::vector3df positionNode;
	for(int k = 0; k < _nodes->getSize(); k++){
		positionNode = _nodes->get(k)->getPosition();
		_nodes->get(k)->setPosition(positionNode.X+FACTOR_FORWARD_SNAKE, positionNode.Y, positionNode.Z);
	}

	_tail->setPosition(_tail->getPosition().X+FACTOR_FORWARD_SNAKE, _tail->getPosition().Y, _tail->getPosition().Z);

	repaintSnake();
}

void platform::Snake::deleteNodes(int __numberNodes)
{
	adjustNodes(__numberNodes, true);
}

void platform::Snake::renderSnake(){
	_head->createNode("meshes/cabeca.ms3d",irr::core::vector3df(0,0,0),irr::core::vector3df(0,0,0),irr::core::vector3df(1,1,1));
	_node->createNode("meshes/corpo.ms3d",irr::core::vector3df(0,0,0),irr::core::vector3df(FACTOR_RANGE_MESH,0,0),irr::core::vector3df(1,1,1));
	_tail->createNode("meshes/cauda.ms3d",irr::core::vector3df(0,0,0),irr::core::vector3df(2*FACTOR_RANGE_MESH,0,0),irr::core::vector3df(1,1,1));
}

void platform::Snake::repaintSnake(){
	_head->repaint();
	_node->repaint();
	_tail->repaint();

	for(int k = 0; k < _nodes->getSize(); k++)
		_nodes->get(k)->repaint();
}

irr::EKEY_CODE* platform::Snake::getHeadMoviments(){
	return _head->getKeyMoviment();
}

base::FrameAnimatedNode* platform::Snake::getHead(){
	return _head;
}
