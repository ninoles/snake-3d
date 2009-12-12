/*
 * PhysisNode.cpp
 *
 *  Created on: 07/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Physis/PhysisNode.h"

using namespace irr;
using namespace physis;

PhysisNode::PhysisNode(){
	_newtonWorld = NULL;
	_collision = NULL;
	_newtonBody = NULL;
	_mesh = NULL;
}

PhysisNode::PhysisNode(NewtonWorld *__newtonWorld){
	_newtonWorld = __newtonWorld;
	_collision = NULL;
	_newtonBody = NULL;
	_mesh = NULL;
}

void PhysisNode::createBody(){
	if(_collision != NULL && _newtonBody != NULL && _newtonWorld != NULL)
		_newtonBody = NewtonCreateBody(_newtonWorld, _collision->getCollisionNode());
}

void PhysisNode::setMassAndInertia(dFloat __mass, dFloat __Ixx, dFloat __Iyy, dFloat __Izz){
	if(_newtonBody != NULL)
		NewtonBodySetMassMatrix(_newtonBody, __mass, __Ixx, __Iyy, __Izz);
}

void PhysisNode::createCollisionFromMesh(irr::scene::IMesh *__mesh){
	if(_collision == NULL){
		_collision = new MeshCollision(_newtonWorld, __mesh);
		_collision->createCollision();
	}
}
