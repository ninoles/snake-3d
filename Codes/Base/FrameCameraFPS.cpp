#include "../../Headers/Base/FrameCameraFPS.h"

base::FrameCameraFPS::FrameCameraFPS(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
		int __id) : base::SceneObjects(__sceneManager, _nWorld, this, __id){

}

base::FrameCameraFPS::FrameCameraFPS(NewtonWorld *_nWorld, irr::scene::ISceneManager *__sceneManager,
            		int __id, irr::scene::ISceneNode* __parent,
        			irr::f32 __rotateSpeed, irr::f32 __moveSpeed, irr::SKeyMap* __keyMapArray,
        			irr::s32 __keyMapSize, bool __noVerticalMovement,
        			irr::f32 __jumpSpeed) : base::SceneObjects(__sceneManager, _nWorld, this, __id){

	_camera = _sceneManager->addCameraSceneNodeFPS(__parent, __rotateSpeed, __moveSpeed, __id, __keyMapArray, __keyMapSize,
			__noVerticalMovement, __jumpSpeed);

	_camera->setRotation(_rotation);
	_camera->setPosition(_position);
	_camera->setScale(_scale);

}

void base::FrameCameraFPS::createCamera(irr::scene::ISceneNode* __parent,
		irr::f32 __rotateSpeed, irr::f32 __moveSpeed, irr::SKeyMap* __keyMapArray,
		irr::s32 __keyMapSize, bool __noVerticalMovement,
		irr::f32 __jumpSpeed){

	_camera = _sceneManager->addCameraSceneNodeFPS(__parent, __rotateSpeed, __moveSpeed, getId(), __keyMapArray, __keyMapSize,
				__noVerticalMovement, __jumpSpeed);

	_camera->setRotation(_rotation);
	_camera->setPosition(_position);
	_camera->setScale(_scale);
}

void base::FrameCameraFPS::dropCamera(){
	_camera->drop();
	dropObject();
}

void base::FrameCameraFPS::repaint(){
	_camera->setRotation(_rotation);
	_camera->setPosition(_position);
	_camera->setScale(_scale);
}

void base::FrameCameraFPS::bindTargetAndRotation(bool __bound){
	_camera->bindTargetAndRotation(__bound);
}

void base::FrameCameraFPS::setAspectRatio(irr::f32 __aspect){
	_camera->setAspectRatio(__aspect);
}

void base::FrameCameraFPS::setFarValue(irr::f32 __farValue){
	_camera->setFarValue(__farValue);
}

void base::FrameCameraFPS::setFOV(irr::f32 __fov){
	_camera->setFOV(__fov);
}

void base::FrameCameraFPS::setInputReceiverEnable(bool __enable){
	_camera->setInputReceiverEnabled(__enable);
}


void base::FrameCameraFPS::setKeyMap(irr::SKeyMap *__map, irr::u32 __count){
	getCameraFPS()->setKeyMap(__map, __count);
}

void base::FrameCameraFPS::setMoveSpeed(irr::f32 __moveSpeed){
	getCameraFPS()->setMoveSpeed(__moveSpeed);
}

void base::FrameCameraFPS::setRotationSpedd(irr::f32 __rotationSpeed){
	getCameraFPS()->setRotateSpeed(__rotationSpeed);
}

void base::FrameCameraFPS::setVerticalMoviment(bool __verticalMov){
	getCameraFPS()->setVerticalMovement(__verticalMov);
}

irr::f32 base::FrameCameraFPS::getMoveSpeed(){
	return getCameraFPS()->getMoveSpeed();
}

irr::f32 base::FrameCameraFPS::getRotateSpeed(){
	return getCameraFPS()->getRotateSpeed();
}

irr::scene::ICameraSceneNode* base::FrameCameraFPS::getCamera(){
	return _camera;
}

irr::scene::ISceneNodeAnimatorCameraFPS* base::FrameCameraFPS::getCameraFPS(){
	return dynamic_cast<irr::scene::ISceneNodeAnimatorCameraFPS*>(_camera);
}

void base::FrameCameraFPS::createTrianguleSelector(irr::scene::ITerrainSceneNode *__terrainNode, irr::core::vector3df __ellipsoidRadius,
							irr::core::vector3df __gravityPerSecond, irr::core::vector3df __ellipsoidTranslation,
							irr::f32 __slidingValue){

	_selector = _sceneManager->createTerrainTriangleSelector(__terrainNode, 0);
	__terrainNode->setTriangleSelector(_selector);

	_animCollision = _sceneManager->createCollisionResponseAnimator(_selector, _camera, __ellipsoidRadius, __gravityPerSecond,
			__ellipsoidTranslation, __slidingValue);

	_camera->addAnimator(_animCollision);
}
