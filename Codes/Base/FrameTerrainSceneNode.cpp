/*
 * FrameTerrainSceneNode.cpp
 *
 *  Created on: 12/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Base/FrameTerrainSceneNode.h"

base::FrameTerrainSceneNode::FrameTerrainSceneNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
			int __id) : base::SceneObjects(__sceneManager, _nWorld, this, __id){

}

base::FrameTerrainSceneNode::FrameTerrainSceneNode(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
			int __id, const irr::c8* __filename, irr::scene::ISceneNode *__parent,
			irr::video::SColor __vertexColor, irr::s32 __maxLOD,
			irr::scene::E_TERRAIN_PATCH_SIZE __patchSize, irr::s32 __smoothFactor) : base::SceneObjects(__sceneManager, _nWorld, this, __id) {

	if(_position.X != 0 && _position.Y != 0 && _position.Z != 0)
		_terrainNode = _sceneManager->addTerrainSceneNode(__filename, __parent, __id, _position, _rotation, _scale, __vertexColor,
				__maxLOD, __patchSize, __smoothFactor);

	_terrainNode->setID(getId());
}

void base::FrameTerrainSceneNode::drop(){
	_terrainNode->drop();
	dropObject();
}

void base::FrameTerrainSceneNode::repaint(){
	_terrainNode->setPosition(_position);
	_terrainNode->setScale(_scale);
	_terrainNode->setRotation(_rotation);
}

void base::FrameTerrainSceneNode::createCollision(){
	_physicalNode->createCollisionFromMesh(getMesh());
}

void base::FrameTerrainSceneNode::scaleTexture(irr::f32 __scale, irr::f32 __scaleTwo){
	_terrainNode->scaleTexture(__scale, __scaleTwo);
}

void base::FrameTerrainSceneNode::setCameraMovimentDelta(irr::f32 __delta){
	_terrainNode->setCameraMovementDelta(__delta);
}

void base::FrameTerrainSceneNode::setCameraRotationDelta(irr::f32 __delta){
	_terrainNode->setCameraRotationDelta(__delta);
}

void base::FrameTerrainSceneNode::setDynamicSelectorUpdate(bool __update){
	_terrainNode->setDynamicSelectorUpdate(__update);
}

void base::FrameTerrainSceneNode::setLODOfPatch(irr::s32 __patchX, irr::s32 __patchZ, irr::s32 __LOD){
	_terrainNode->setLODOfPatch(__patchX, __patchZ, __LOD);
}

irr::core::aabbox3d<irr::f32> base::FrameTerrainSceneNode::getBoundingBox(){
	return _terrainNode->getBoundingBox();
}

irr::f32 base::FrameTerrainSceneNode::getHeight(irr::f32 __pX, irr::f32 __pY){
	return _terrainNode->getHeight(__pX, __pY);
}

irr::u32 base::FrameTerrainSceneNode::getIndexCount(){
	return _terrainNode->getIndexCount();
}

irr::core::vector3df base::FrameTerrainSceneNode::getTerrainCenter(){
	return _terrainNode->getTerrainCenter();
}

void base::FrameTerrainSceneNode::setMaterialFlag(irr::video::E_MATERIAL_FLAG __flag, bool __newvalue){
	_terrainNode->setMaterialFlag(__flag, __newvalue);
}

void base::FrameTerrainSceneNode::setTexture(irr::u32 __textureLayer, irr::video::ITexture *__texture){
	_terrainNode->setMaterialTexture(__textureLayer, __texture);
}

void base::FrameTerrainSceneNode::setMaterialType(irr::video::E_MATERIAL_TYPE __newType){
	_terrainNode->setMaterialType(__newType);
}

void base::FrameTerrainSceneNode::setVisible(bool __visible){
	_terrainNode->setVisible(__visible);
}

void base::FrameTerrainSceneNode::updateAbsolutePosition(){
	_terrainNode->updateAbsolutePosition();
}

irr::core::aabbox3d<irr::f32> base::FrameTerrainSceneNode::getTranformedBoundingBox(){
	_terrainNode->getTransformedBoundingBox();
}

irr::core::matrix4 base::FrameTerrainSceneNode::getRelativeTranformation(){
	_terrainNode->getRelativeTransformation();
}

irr::core::vector3df base::FrameTerrainSceneNode::getAbsolutePosition(){
	_terrainNode->getAbsolutePosition();
}

irr::scene::ESCENE_NODE_TYPE base::FrameTerrainSceneNode::getType(){
	_terrainNode->getType();
}

irr::scene::ISceneNode* base::FrameTerrainSceneNode::getParent(){
	_terrainNode->getParent();
}

irr::scene::ITerrainSceneNode* base::FrameTerrainSceneNode::getTerrainNode(){
	return _terrainNode;
}

irr::scene::ISceneNode* base::FrameTerrainSceneNode::getSceneNode(){
	return dynamic_cast<irr::scene::ISceneNode*>(_terrainNode);
}

irr::scene::IMesh* base::FrameTerrainSceneNode::getMesh(){
	return _terrainNode->getMesh();
}

