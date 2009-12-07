/*
 * PhysisNode.cpp
 *
 *  Created on: 07/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Physis/PhysisNode.h"

using namespace irr;
using namespace base;
using namespace physis;

PhysisNode::PhysisNode(){
	_collision = NULL;
	_newtonBody = NULL;
	_node = NULL;
}

void PhysisNode::setNode(scene::ISceneNode *__node, int __id){
	_node = new FrameSceneNode(__node, __id);
}

void PhysisNode::setBody(NewtonBody *__body){
	_newtonBody = __body;
}

void PhysisNode::setCollisionFromMesh(NewtonWorld *__newtonWorld){
	_collision = new MeshCollision(_newtonBody, __newtonWorld, _node);
}
