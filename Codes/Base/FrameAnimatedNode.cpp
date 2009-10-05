#include "../../Headers/Base/FrameAnimatedNode.h"

using namespace base;

FrameAnimatedNode::FrameAnimatedNode(irr::scene::IAnimatedMeshSceneNode* __animatedNode){
    _mesh = __animatedNode;
}

void FrameAnimatedNode::setAnimatedSceneNode(irr::scene::IAnimatedMeshSceneNode* __animatedNode){
    _mesh = __animatedNode;
}

irr::scene::IAnimatedMeshSceneNode* FrameAnimatedNode::getAnimatedScene(){
    return _mesh;
}
