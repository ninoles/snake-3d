#include "../../Headers/Base/FrameCameraMaya.h"

base::FrameCameraMaya::FrameCameraMaya(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
		int __id) : base::SceneObjects(__sceneManager, _nWorld, this, __id){

}

base::FrameCameraMaya::FrameCameraMaya(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
					int __id, irr::scene::ISceneNode* __parent, irr::f32 __rotateSpeed,
					irr::f32 __zoomSpeed, irr::f32 __translationSpeed)
					: base::SceneObjects(__sceneManager, _nWorld, this, __id){

	_sceneManager->addCameraSceneNodeMaya(__parent, __rotateSpeed, __zoomSpeed, __translationSpeed, __id);

	_camera->setRotation(_rotation);
	_camera->setPosition(_position);
	_camera->setScale(_scale);

}

void base::FrameCameraMaya::createCamera(irr::scene::ISceneNode* __parent, irr::f32 __rotateSpeed,
		irr::f32 __zoomSpeed, irr::f32 __translationSpeed){

	_sceneManager->addCameraSceneNodeMaya(__parent, __rotateSpeed, __zoomSpeed, __translationSpeed, getId());

	_camera->setRotation(_rotation);
	_camera->setPosition(_position);
	_camera->setScale(_scale);
}

void base::FrameCameraMaya::dropCamera(){
	_camera->drop();
	dropObject();
}

void base::FrameCameraMaya::repaint(){
	_camera->setRotation(_rotation);
	_camera->setPosition(_position);
	_camera->setScale(_scale);
}

void base::FrameCameraMaya::bindTargetAndRotation(bool __bound){
	_camera->bindTargetAndRotation(__bound);
}

void base::FrameCameraMaya::setAspectRatio(irr::f32 __aspect){
	_camera->setAspectRatio(__aspect);
}

void base::FrameCameraMaya::setFarValue(irr::f32 __farValue){
	_camera->setFarValue(__farValue);
}

void base::FrameCameraMaya::setFOV(irr::f32 __fov){
	_camera->setFOV(__fov);
}

void base::FrameCameraMaya::setInputReceiverEnable(bool __enable){
	_camera->setInputReceiverEnabled(__enable);
}

void base::FrameCameraMaya::setMoveSpeed(irr::f32 __moveSpeed){
	getCameraMaya()->setMoveSpeed(__moveSpeed);
}

void base::FrameCameraMaya::setRotationSpedd(irr::f32 __rotationSpeed){
	getCameraMaya()->setRotateSpeed(__rotationSpeed);
}

void base::FrameCameraMaya::setZoomSpeed(irr::f32 __zoomSpeed){
	getCameraMaya()->setZoomSpeed(__zoomSpeed);
}

irr::f32 base::FrameCameraMaya::getMoveSpeed(){
	return getCameraMaya()->getMoveSpeed();
}

irr::f32 base::FrameCameraMaya::getRotateSpeed(){
	return getCameraMaya()->getRotateSpeed();
}

irr::f32 base::FrameCameraMaya::getZooomSpeed(){
	return getCameraMaya()->getZoomSpeed();
}

irr::scene::ICameraSceneNode* base::FrameCameraMaya::getCamera(){
	return _camera;
}

irr::scene::ISceneNodeAnimatorCameraMaya* base::FrameCameraMaya::getCameraMaya(){
	return dynamic_cast<irr::scene::ISceneNodeAnimatorCameraMaya*>(_camera);
}

void base::FrameCameraMaya::createTrianguleSelector(irr::scene::ITerrainSceneNode *__terrainNode, irr::core::vector3df __ellipsoidRadius,
							irr::core::vector3df __gravityPerSecond, irr::core::vector3df __ellipsoidTranslation,
							irr::f32 __slidingValue){

	_selector = _sceneManager->createTerrainTriangleSelector(__terrainNode, 0);
	__terrainNode->setTriangleSelector(_selector);

	_animCollision = _sceneManager->createCollisionResponseAnimator(_selector, _camera, __ellipsoidRadius, __gravityPerSecond,
			__ellipsoidTranslation, __slidingValue);

	_camera->addAnimator(_animCollision);
}
