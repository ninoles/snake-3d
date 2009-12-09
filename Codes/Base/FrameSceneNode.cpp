#include "../../Headers/Base/FrameSceneNode.h"

using namespace base;

FrameSceneNode::FrameSceneNode(){

}

FrameSceneNode::FrameSceneNode(irr::scene::ISceneNode* __sceneNode, signed int __id){
    _sceneNode = __sceneNode;
    _id = __id;
}

void FrameSceneNode::setSceneNode(irr::scene::ISceneNode* __sceneNode){
    _sceneNode = __sceneNode;
}

irr::scene::ISceneNode* FrameSceneNode::getSceneNode(){
    return _sceneNode;
}

void FrameSceneNode::setCollisionNode(NewtonCollision *__collision){
	_collision = __collision;
}

NewtonCollision* FrameSceneNode::getCollision(){
	return _collision;
}

signed int FrameSceneNode::getId(){
	return _id;
}
