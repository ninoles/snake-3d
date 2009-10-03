#include "../../Headers/Base/FrameSceneNode.h"

using namespace base;

void FrameSceneNode::setNodeMoviment(Events::NodeMoviment* __movimentNode){
    _movimentNode = __movimentNode;
}

Events::NodeMoviment* FrameSceneNode::getNodeMoviment(){
    return _movimentNode;
}


