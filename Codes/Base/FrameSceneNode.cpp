#include "../../Headers/Base/FrameSceneNode.h"

using namespace base;

FrameSceneNode::FrameSceneNode(irr::scene::ISceneNode* __sceneNode){
    _sceneNode = __sceneNode;
}

void FrameSceneNode::setSceneNode(irr::scene::ISceneNode* __sceneNode){
    _sceneNode = __sceneNode;
}

irr::scene::ISceneNode* FrameSceneNode::getSceneNode(){
    return _sceneNode;
}

void FrameSceneNode::setNodeMoviment(Events::NodeMoviment* __movimentNode){
    _movimentNode = __movimentNode;
}

Events::NodeMoviment* FrameSceneNode::getNodeMoviment(){
    return _movimentNode;
}


