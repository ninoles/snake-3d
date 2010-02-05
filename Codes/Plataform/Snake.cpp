/*
 * Snake.cpp
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Snake.h"
#include <iostream>

platform::Snake::Snake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW){
	_nodes = new GenericList::ArrayList<base::FrameAnimatedNode*>();
	_indexCounterBreak = 0;

	for(int i = 0; i < MAX_TURNS; i++){
		_counterBreak[i] = -1;
		_directions[i] = base::NOTHING;
	}

	_sceneManager = __sceneManager;
	_absolutePositionFromHead = __initialPosition;

	_cameraSnake = new base::FrameCameraFPS(__newtonW, __sceneManager, 100);

	_head = new base::FrameAnimatedNode(__newtonW, __sceneManager, 0);
	_tail = new base::FrameAnimatedNode(__newtonW, __sceneManager, 1);

	for(int k = 0; k < MAX_TAM_SNAKE; ++k)
		_node[k].initComponent(__newtonW, __sceneManager, k);

	_nodes->add(_head);
	_nodes->add(&_node[0]);
	_nodes->add(&_node[1]);
	_nodes->add(&_node[2]);
	_nodes->add(_tail);

	for(int k = 0; k < _nodes->getSize(); ++k)
		_nodes->get(k)->setDirection(base::NORTH);

	renderSnake();
	renderCamera();

	_head->createCollision();
	_tail->createCollision();
}

platform::Snake::Snake(){
	_nodes = new GenericList::ArrayList<base::FrameAnimatedNode*>();
	_indexCounterBreak = 0;

	for(int i = 0; i < MAX_TURNS; ++i){
		_counterBreak[i] = -1;
		_directions[i] = base::NOTHING;
	}
}

void platform::Snake::createSnake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW){
	_sceneManager = __sceneManager;
	_absolutePositionFromHead = __initialPosition;

	_cameraSnake = new base::FrameCameraFPS(__newtonW, __sceneManager, 100);

	_head = new base::FrameAnimatedNode(__newtonW, __sceneManager, 0);
	_tail = new base::FrameAnimatedNode(__newtonW, __sceneManager, 1);

	for(int k = 0; k < MAX_TAM_SNAKE; ++k){
		_node[k].initComponent(__newtonW, __sceneManager, k+100);
		_node[k].createNode("snake/corpo.ms3d",irr::core::vector3df(0,0,0),irr::core::vector3df(0,0,0),irr::core::vector3df(0.3,0.3,0.3));
		_node[k].createCollision();
		_node[k].setVisible(false);
	}

	_node[0].setVisible(true);
	_node[1].setVisible(true);
	_node[2].setVisible(true);

	_nodes->add(_head);
	_nodes->add(&_node[0]);
	_nodes->add(&_node[1]);
	_nodes->add(&_node[2]);
	_nodes->add(_tail);

	for(int k = 0; k < _nodes->getSize(); ++k)
		_nodes->get(k)->setDirection(base::NORTH);

	renderSnake();
	renderCamera();

	_head->createCollision();
	_tail->createCollision();

}

//False -> Move the tail back
//True -> Move the tail front
void platform::Snake::adjustNodes(irr::core::vector3df __newPositionFromLastNode, bool __adjust){

	if(__adjust){
		_tail->setPosition(__newPositionFromLastNode.X, _tail->getPosition().Y, _tail->getPosition().Z+ (2*FACTOR_RANGE_MESH));
	} else {
		_nodes->get(_nodes->getSize()-2)->setPosition(__newPositionFromLastNode.X, __newPositionFromLastNode.Y, __newPositionFromLastNode.Z + FACTOR_RANGE_MESH);
		_tail->setPosition(__newPositionFromLastNode.X, _tail->getPosition().Y, __newPositionFromLastNode.Z + (2.6*FACTOR_RANGE_MESH));
	}

}

//False -> Insert Node
//True -> Remove Nodes
void platform::Snake::adjustNodes(int __numberNodes, bool __adjust){
	if(__adjust){
		_nodes->remove(_nodes->getSize()-2);

		adjustNodes(_nodes->get(_nodes->getSize()-2)->getPosition(), __adjust);
	} else {

		if(_nodes->getSize() < MAX_TAM_SNAKE){

			_nodes->remove(_nodes->getSize()-1);		//Remove the tail from snake
			_nodes->add(&_node[_nodes->getSize()]);		//Add body in the snake
			_nodes->add(_tail);							//Add tail in the final snake
			_node[_nodes->getSize()].setVisible(true);

			adjustNodes(_nodes->get(_nodes->getSize()-3)->getPosition(), __adjust);	//Position of last body

		}
	}

	repaintSnake();
}

void platform::Snake::adjustCounter(){
	if(_indexCounterBreak == 0)
		_counterBreak[_indexCounterBreak] = (_nodes->getSize()/2);
	else
		_counterBreak[_indexCounterBreak] = (_counterBreak[_indexCounterBreak-1]/2);
}

void platform::Snake::turnBodyLeft(int __factorRotation){

	irr::core::vector3df rotation;
	base::directions direction;

	for(int k = 1; k <= _counterBreak[_indexCounterBreak]; ++k){

		direction = _head->getDirection();
		_nodes->get(k)->setDirection(direction);

		rotation = _nodes->get(k)->getRotation().rotationToDirection(irr::core::vector3df(0,DEGRESS_TURN*3*__factorRotation,0));
		_nodes->get(k)->setRotation(rotation.X, rotation.Y, rotation.Z);

	}

	++_indexCounterBreak;
}

void platform::Snake::turnBodyRight(int __factorRotation){

	irr::core::vector3df rotation;
	base::directions direction;

	for(int k = 1; k <= _counterBreak[_indexCounterBreak]; ++k){

		direction = _head->getDirection();
		_nodes->get(k)->setDirection(direction);

		rotation = _nodes->get(k)->getRotation().rotationToDirection(irr::core::vector3df(0,DEGRESS_TURN*__factorRotation,0));
		_nodes->get(k)->setRotation(rotation.X, rotation.Y, rotation.Z);

	}

	++_indexCounterBreak;

}

void platform::Snake::turnLeft(){

	if(_indexCounterBreak >= MAX_TURNS)
		return;

	adjustCounter();

	int factor = 1;
	irr::core::vector3df rotation;
	base::directions direction;

	direction = _head->getDirection();

	//Rotate the head
	if(direction == base::NORTH)
		_head->setDirection(base::WEST);
	else if(direction == base::EAST){
		_head->setDirection(base::NORTH);
		factor = 4;
	}
	else if(direction == base::SOUTH){
		_head->setDirection(base::EAST);
		factor = 3;
	}
	else if(direction == base::WEST){
		_head->setDirection(base::SOUTH);
		factor = 2;
	}
	_directions[_indexCounterBreak] = _head->getDirection();

	rotation = _head->getRotation().rotationToDirection(irr::core::vector3df(0,DEGRESS_TURN*3*factor,0));
	_head->setRotation(rotation.X, rotation.Y, rotation.Z);

	//Rotate the body
	turnBodyLeft(factor);
	reposition(true);
	repaintSnake();

}

void platform::Snake::turnRight(){

	if(_indexCounterBreak >= MAX_TURNS)
		return;

	adjustCounter();

	int factor = 1;
	irr::core::vector3df rotation;
	base::directions direction;

	//Rotate the head
	direction = _head->getDirection();

	if(direction == base::NORTH)
		_head->setDirection(base::EAST);
	else if(direction == base::EAST){
		_head->setDirection(base::SOUTH);
		factor = 2;
	}
	else if(direction == base::SOUTH){
		_head->setDirection(base::WEST);
		factor = 3;
	}
	else if(direction == base::WEST){
		_head->setDirection(base::NORTH);
		factor = 4;
	}
	_directions[_indexCounterBreak] = _head->getDirection();

	//Adjust rotation of head
	rotation = _head->getRotation().rotationToDirection(irr::core::vector3df(0,DEGRESS_TURN*factor,0));
	_head->setRotation(rotation.X, rotation.Y, rotation.Z);

	//Rotate the body
	turnBodyRight(factor);
	reposition(true);
	repaintSnake();

}

void platform::Snake::insertNode(){
	adjustNodes(1, false);
}

void platform::Snake::insertMoviment(int __idPlayer){

	if(__idPlayer == 1){
		_leftMoviment = irr::KEY_KEY_A;
		_rightMoviment = irr::KEY_KEY_D;
	} else if(__idPlayer == 2){
		_leftMoviment = irr::KEY_KEY_J;
		_rightMoviment = irr::KEY_KEY_L;
	}

}

void platform::Snake::snakeForward(){

	irr::core::vector3df positionNode;

	for(int k = 0; k < _nodes->getSize(); ++k){

		positionNode = _nodes->get(k)->getPosition();

		switch(_nodes->get(k)->getDirection()){

			case base::NORTH:
				_nodes->get(k)->setPosition(positionNode.X, positionNode.Y, positionNode.Z-FACTOR_FORWARD_SNAKE);
				break;

			case base::WEST:
				_nodes->get(k)->setPosition(positionNode.X+FACTOR_FORWARD_SNAKE, positionNode.Y, positionNode.Z);
				break;

			case base::SOUTH:
				_nodes->get(k)->setPosition(positionNode.X, positionNode.Y, positionNode.Z+FACTOR_FORWARD_SNAKE);
				break;

			case base::EAST:
				_nodes->get(k)->setPosition(positionNode.X-FACTOR_FORWARD_SNAKE, positionNode.Y, positionNode.Z);
				break;

			case base::NOTHING:
				break;

		}
	}

	incrementCounters();
	reposition(false);
	repaintSnake();
	repaintCamera();

	//std::cout << "Posicao X: " << _head->getPosition().X << " Posicao Y: " << _head->getPosition().Y << " Posicao Z: " << _head->getPosition().Z << std::endl;
}

void platform::Snake::deleteNodes(int __numberNodes)
{
	adjustNodes(__numberNodes, true);
}

void platform::Snake::renderSnake(){
	_head->createNode("snake/cabeca.ms3d",irr::core::vector3df(0,0,0), irr::core::vector3df(_absolutePositionFromHead.X,_absolutePositionFromHead.Y,_absolutePositionFromHead.Z+0.5),irr::core::vector3df(0.3,0.3,0.3));

	for(int k = 1; k < _nodes->getSize()-1; k++){
		_nodes->get(k)->setPosition(_absolutePositionFromHead.X, _absolutePositionFromHead.Y, _absolutePositionFromHead.Z+FACTOR_RANGE_MESH*k);
		_nodes->get(k)->repaint();
	}

	_tail->createNode("snake/cauda.ms3d",irr::core::vector3df(0,0,0),irr::core::vector3df(_absolutePositionFromHead.X,_absolutePositionFromHead.Y,_absolutePositionFromHead.Z+(6.4*FACTOR_RANGE_MESH)),irr::core::vector3df(0.3,0.3,0.3));
}

void platform::Snake::renderCamera(){
	_cameraSnake->createCamera(0, 5.f, 0.3f, 0, 0, true, 0);
	_cameraSnake->setInputReceiverEnable(false);	//The camera can not be moved
	_cameraSnake->setPosition(_tail->getPosition().X, _tail->getPosition().Y+3, _tail->getPosition().Z);
	_cameraSnake->setRotation(_tail->getRotation().X+180, _tail->getRotation().Y, _tail->getRotation().Z);
}

void platform::Snake::reposition(bool __moviment){

	irr::core::vector3df position;
	irr::core::vector3df rotation;
	irr::core::vector3df rotationTail;
	base::directions direction;

	if(_indexCounterBreak > 0 && __moviment){

		position = _head->getPosition();

		for(int i = 0; i < _indexCounterBreak; ++i){

			for(int k = 1; k <= _counterBreak[i]; ++k){

				switch(_directions[i]){

					case base::NORTH:
						_nodes->get(k)->setPosition(position.X, position.Y, position.Z+(k * FACTOR_RANGE_MESH)-0.13);
						break;

					case base::SOUTH:
						_nodes->get(k)->setPosition(position.X, position.Y, position.Z-(k * FACTOR_RANGE_MESH)+0.13);
						break;

					case base::WEST:
						_nodes->get(k)->setPosition(position.X-(k * FACTOR_RANGE_MESH)+0.13, position.Y, position.Z);
						break;

					case base::EAST:
						_nodes->get(k)->setPosition(position.X + (k * FACTOR_RANGE_MESH)-0.13, position.Y, position.Z);
						break;

					case base::NOTHING:
						break;

				}
			}
		}
	}

	else if(isBreakEnd()){	//Align the tail

		rotation = _nodes->get(_nodes->getSize()-2)->getRotation();
		position = _nodes->get(_nodes->getSize()-2)->getPosition();
		direction = _nodes->get(_nodes->getSize()-2)->getDirection();

		rotationTail = _tail->getRotation().rotationToDirection(rotation);
		_tail->setRotation(-(rotationTail.X), rotationTail.Y, rotationTail.Z);

		//std::cerr << "Rotacao X: " << rotationTail.X << " Rotacao Y: " << rotationTail.Y << " Rotacao Z: " << rotationTail.Z << std::endl;

		switch(direction){

			case base::NORTH:
				_tail->setPosition(position.X, position.Y, position.Z + (FACTOR_RANGE_MESH*2));
				break;

			case base::SOUTH:
				_tail->setPosition(position.X, position.Y, position.Z - (FACTOR_RANGE_MESH*2));
				break;

			case base::WEST:
				_tail->setPosition(position.X -(FACTOR_RANGE_MESH*2), position.Y, position.Z);
				break;

			case base::EAST:
				_tail->setPosition(position.X + (FACTOR_RANGE_MESH*2), position.Y, position.Z);
				break;

			case base::NOTHING:
				break;

		}

		_tail->setDirection(direction);
	}

	else if(_indexCounterBreak > 0 && !__moviment){

		position = _head->getPosition();

		for(int i = 0; i < _indexCounterBreak; ++i){

			rotation = _nodes->get(_counterBreak[i]-1)->getRotation();

			switch(_directions[i]){

				case base::NORTH:
					_nodes->get(_counterBreak[i])->setPosition(position.X, position.Y, position.Z+(_counterBreak[i] * FACTOR_RANGE_MESH));
					break;

				case base::SOUTH:
					_nodes->get(_counterBreak[i])->setPosition(position.X, position.Y, position.Z-(_counterBreak[i] * FACTOR_RANGE_MESH));
					break;

				case base::WEST:
					_nodes->get(_counterBreak[i])->setPosition(position.X-(_counterBreak[i] * FACTOR_RANGE_MESH), position.Y, position.Z);
					break;

				case base::EAST:
					_nodes->get(_counterBreak[i])->setPosition(position.X + (_counterBreak[i] * FACTOR_RANGE_MESH), position.Y, position.Z);
					break;

				case base::NOTHING:
					break;

			}

			rotationTail = _nodes->get(_counterBreak[i])->getRotation().rotationToDirection(rotation);

			_nodes->get(_counterBreak[i])->setRotation(rotationTail.X, rotationTail.Y, rotationTail.Z);
			_nodes->get(_counterBreak[i])->setDirection(_directions[i]);

			std::cout << "Rotacao X: " << rotationTail.X << " Rotacao Y: " << rotationTail.Y << " Rotacao Z: " << rotationTail.Z << std::endl;

		}
	}
}

void platform::Snake::incrementCounters(){
	for(int k = 0; k < _indexCounterBreak; ++k)
		_counterBreak[k]++;
}

bool platform::Snake::isBreakEnd(){

	if(_counterBreak[0] == _nodes->getSize()){

		_counterBreak[0] = -1;
		_directions[0] = base::NOTHING;

		for(int k = 0; k < _indexCounterBreak-1; ++k){
			_counterBreak[k] =  _counterBreak[_indexCounterBreak+1];
			_directions[k] = _directions[k+1];
		}

		--_indexCounterBreak;

		return true;
	}

	return false;
}

void platform::Snake::repaintSnake(){
	for(int k = 0; k < _nodes->getSize(); ++k)
		_nodes->get(k)->repaint();
}

void platform::Snake::repaintCamera(){

	switch(_tail->getDirection()){

		case base::NORTH:
			_cameraSnake->setPosition(_tail->getPosition().X, _tail->getPosition().Y+3, _tail->getPosition().Z+8);
			break;
		case base::EAST:
			_cameraSnake->setPosition(_tail->getPosition().X+8, _tail->getPosition().Y+3, _tail->getPosition().Z);
			break;
		case base::SOUTH:
			_cameraSnake->setPosition(_tail->getPosition().X, _tail->getPosition().Y+3, _tail->getPosition().Z-8);
			break;
		case base::WEST:
			_cameraSnake->setPosition(_tail->getPosition().X-8, _tail->getPosition().Y+3, _tail->getPosition().Z);
			break;
		case base::NOTHING:
			break;
	}

	_cameraSnake->setRotation(_tail->getRotation().X+180, _tail->getRotation().Y, _tail->getRotation().Z);
	_cameraSnake->repaint();
}

irr::EKEY_CODE platform::Snake::getMovimentLeft(){
	return _leftMoviment;
}

irr::EKEY_CODE platform::Snake::getMovimentRight(){
	return _rightMoviment;
}

base::FrameAnimatedNode* platform::Snake::getHead(){
	return _head;
}

base::FrameCameraFPS* platform::Snake::getCamera(){
	return _cameraSnake;
}

#include "../GenericList/ArrayList.cpp"
