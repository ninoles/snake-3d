#include "../../Headers/Base/FrameSkyBox.h"

base::FrameSkyBox::FrameSkyBox(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id) : base::SceneObjects(__sceneManager, _nWorld, this, __id){

}

base::FrameSkyBox::FrameSkyBox(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
		int __id, const irr::c8* __textureUp,
		const irr::c8* __textureDown, const irr::c8* __textureLeft,
		const irr::c8* __textureRight, const irr::c8* __textureFt,
		const irr::c8* __textureBk, irr::scene::ISceneNode *__parent) : base::SceneObjects(__sceneManager, _nWorld, this, __id){

	//_skyBox = _sceneManager->addSkyBoxSceneNode();

	_skyBox->setID(getId());

}

//Main Methods
void base::FrameSkyBox::createNode( const irr::c8* __textureUp,
		const irr::c8* __textureDown, const irr::c8* __textureLeft,
		const irr::c8* __textureRight, const irr::c8* __textureFt,
		const irr::c8* __textureBk, irr::scene::ISceneNode *__parent){

	//_skyBox = _sceneManager->addSkyBoxSceneNode();
	_skyBox->setID(getId());

}

void base::FrameSkyBox::repaint(){

}

void base::FrameSkyBox::drop(){
	_skyBox->drop();
	dropObject();
}

void base::FrameSkyBox::createCollision(){
	_physicalNode->createCollisionFromMesh(getMesh());
}

//Mesh Methods
void base::FrameSkyBox::setMaterialFlag(irr::video::E_MATERIAL_FLAG __flag, bool __newvalue){
	_skyBox->setMaterialFlag(__flag, __newvalue);
}

void base::FrameSkyBox::setTexture(irr::u32 __textureLayer, irr::video::ITexture *__texture){
	_skyBox->setMaterialTexture(__textureLayer, __texture);
}

void base::FrameSkyBox::setMaterialType(irr::video::E_MATERIAL_TYPE __newType){
	_skyBox->setMaterialType(__newType);
}

void base::FrameSkyBox::setVisible(bool __visible){
	_skyBox->setVisible(__visible);
}

void base::FrameSkyBox::updateAbsolutePosition(){
	_skyBox->updateAbsolutePosition();
}

irr::core::aabbox3d<irr::f32> base::FrameSkyBox::getTranformedBoundingBox(){
	return _skyBox->getTransformedBoundingBox();
}

irr::core::matrix4 base::FrameSkyBox::getRelativeTranformation(){
	return _skyBox->getRelativeTransformation();
}

irr::core::vector3df base::FrameSkyBox::getAbsolutePosition(){
	return _skyBox->getAbsolutePosition();
}

irr::scene::ESCENE_NODE_TYPE base::FrameSkyBox::getType(){
	return _skyBox->getType();
}

irr::scene::ISceneNode* base::FrameSkyBox::getParent(){
	return _skyBox->getParent();
}

irr::scene::ISceneNode* base::FrameSkyBox::getSkyBox(){
	return _skyBox;
}

irr::scene::IMesh* base::FrameSkyBox::getMesh(){
	return (dynamic_cast<irr::scene::IMeshSceneNode*>(_skyBox))->getMesh();
}
