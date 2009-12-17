#include "../../Headers/Base/FrameAnimatedNode.h"

base::FrameAnimatedNode::FrameAnimatedNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
		int __id) : SceneObjects(__sceneManager, _nWorld, this, __id){
}

base::FrameAnimatedNode::FrameAnimatedNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
		int __id, const irr::c8* __filename, irr::core::vector3df __rotarion, irr::core::vector3df __position,
		irr::core::vector3df __scale) : SceneObjects(__sceneManager, _nWorld, this, __id){

	_mesh = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(__filename));

	_mesh->setRotation(__rotarion);
	_mesh->setPosition(__position);
	_mesh->setScale(__scale);

	setPosition(__position.X, __position.Y, __position.Z);
	setRotation(__rotarion.X, __rotarion.Y, __rotarion.Z);
	setScale(__rotarion.X, __rotarion.Y, __rotarion.Z);

	_mesh->setID(getId());
}

void base::FrameAnimatedNode::createNode(const irr::c8* __filename){
	_mesh = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(__filename));

	_mesh->setRotation(_rotation);
	_mesh->setPosition(_position);
	_mesh->setScale(_scale);

	_mesh->setID(getId());
}

void base::FrameAnimatedNode::repaint(){
	_mesh->setRotation(_rotation);
	_mesh->setPosition(_position);
	_mesh->setScale(_scale);
}

void base::FrameAnimatedNode::drop(){
	dropObject();
	_mesh->drop();
}

void base::FrameAnimatedNode::createCollision(){
	_physicalNode->createCollisionFromMesh(getMesh());
}

irr::scene::IAnimatedMeshSceneNode* base::FrameAnimatedNode::getAnimatedMesh(){
	return _mesh;
}

irr::scene::ISceneNode* base::FrameAnimatedNode::getSceneNode(){
	return dynamic_cast<irr::scene::ISceneNode*>(_mesh);
}

irr::scene::IMesh* base::FrameAnimatedNode::getMesh(){
	return dynamic_cast<irr::scene::IMesh*>(_mesh->getMesh());
}

void base::FrameAnimatedNode::setMaterialFlag(irr::video::E_MATERIAL_FLAG __flag, bool __newvalue){
	_mesh->setMaterialFlag(__flag, __newvalue);
}

void base::FrameAnimatedNode::setTexture(irr::u32 __textureLayer, irr::video::ITexture *__texture){
	_mesh->setMaterialTexture(__textureLayer, __texture);
}

void base::FrameAnimatedNode::setMaterialType(irr::video::E_MATERIAL_TYPE __newType){
	_mesh->setMaterialType(__newType);
}

void base::FrameAnimatedNode::setVisible(bool __visible){
	_mesh->setVisible(__visible);
}

void base::FrameAnimatedNode::updateAbsolutePosition(){
	_mesh->updateAbsolutePosition();
}

irr::core::aabbox3d<irr::f32> base::FrameAnimatedNode::getTranformedBoundingBox(){
	return _mesh->getTransformedBoundingBox();
}

irr::core::matrix4 base::FrameAnimatedNode::getRelativeTranformation(){
	return _mesh->getRelativeTransformation();
}

irr::core::vector3df base::FrameAnimatedNode::getAbsolutePosition(){
	return _mesh->getAbsolutePosition();
}

irr::scene::ESCENE_NODE_TYPE base::FrameAnimatedNode::getType(){
	return _mesh->getType();
}

irr::scene::ISceneNode* base::FrameAnimatedNode::getParent(){
	return _mesh->getParent();
}

irr::s32 base::FrameAnimatedNode::getStartFrame(){
	return _mesh->getStartFrame();
}

irr::s32 base::FrameAnimatedNode::getFinalFrame(){
	return _mesh->getEndFrame();
}

irr::f32 base::FrameAnimatedNode::getCurrentFrame(){
	return _mesh->getFrameNr();
}

void base::FrameAnimatedNode::setCurrentFrame(irr::f32 __frame){
	_mesh->setCurrentFrame(__frame);
}

void base::FrameAnimatedNode::setFrameLoop(irr::f32 __start, irr::f32 __end){
	_mesh->setFrameLoop(__start, __end);
}

void base::FrameAnimatedNode::setAnimationSpeed(irr::f32 __framePerSecond){
	_mesh->setAnimationSpeed(__framePerSecond);
}
