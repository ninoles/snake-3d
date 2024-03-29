/*
 * Point.cpp
 *
 *  Created on: 30/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Point.h"

platform::Point::Point(irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW, int __id){
	_mesh = new base::FrameAnimatedNode(__newtonW, __sceneManager, 100);
	_value = 10;
	_currentRepetition = 0;

	initComponent();

}

void platform::Point::initComponent(){
	_mesh->createNode("plants/ponto.3ds", irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0), irr::core::vector3df(3, 3, 3));
	_mesh->createCollision();
	_mesh->setVisible(false);
}

void platform::Point::insertPointInPosition(irr::core::vector3df __position){
	_mesh->setPosition(__position.X, __position.Y, __position.Z);
	_mesh->repaint();
	_mesh->setVisible(true);
}

void platform::Point::setVisible(bool __visible){
	_mesh->setVisible(__visible);
}

void platform::Point::setMaxPoints(int __maxPoints){
	_value = __maxPoints/10;
}

int platform::Point::getValue(){
	return _value;
}

bool platform::Point::isRepetitions(){
	return	_currentRepetition <= REPETITIONS;
}

base::FrameAnimatedNode* platform::Point::getAnimatedNode(){
	return _mesh;
}
