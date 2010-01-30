/*
 * SceneObjects.cpp
 *
 *  Created on: 10/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Base/SceneObjects.h"

base::SceneObjects::SceneObjects(irr::scene::ISceneManager *__sceneManager, NewtonWorld *_nWorld,
		void *__sceneObject, int __id) : BasicObject(__sceneObject, __id){

	_sceneManager = __sceneManager;
	_physicalNode = new physis::PhysisNode(_nWorld);

}

base::SceneObjects::SceneObjects() : BasicObject(){

}

void base::SceneObjects::initObj(irr::scene::ISceneManager *__sceneManager, NewtonWorld *_nWorld, void *__sceneObject, int __id){
	init(__sceneObject, __id);

	_sceneManager = __sceneManager;
	_physicalNode = new physis::PhysisNode(_nWorld);
}

void base::SceneObjects::setPosition(float __pX, float __pY, float __pZ){
	_position.X = __pX;
	_position.Y = __pY;
	_position.Z = __pZ;
}

void base::SceneObjects::setRotation(float __rX, float __rY, float __rZ){
	_rotation.X = __rX;
	_rotation.Y = __rY;
	_rotation.Z = __rZ;
}

void base::SceneObjects::setScale(float __sX, float __sY, float __sZ){
	_scale.X = __sX;
	_scale.Y = __sY;
	_scale.Z = __sZ;
}

physis::PhysisNode* base::SceneObjects::getPhysisNode(){
	return _physicalNode;
}

irr::core::vector3df base::SceneObjects::getPosition(){
	return _position;
}

irr::core::vector3df base::SceneObjects::getScale(){
	return _scale;
}

irr::core::vector3df base::SceneObjects::getRotation(){
	return _rotation;
}
