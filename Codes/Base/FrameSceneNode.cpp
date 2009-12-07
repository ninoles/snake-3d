#include "../../Headers/Base/FrameSceneNode.h"

using namespace base;

FrameSceneNode::FrameSceneNode(){

}

FrameSceneNode::FrameSceneNode(irr::scene::ISceneNode* __sceneNode, int __id){
    _sceneNode = __sceneNode;
    _id = __id;
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


