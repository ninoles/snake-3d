/*
 * Point.cpp
 *
 *  Created on: 29/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Base/FrameLight.h"

base::FrameLight::FrameLight(NewtonWorld *__newtonW, irr::scene::ISceneManager *__sceneManager, int __id)
	: base::SceneObjects(__sceneManager, __newtonW, this, __id){

}

base::FrameLight::FrameLight(NewtonWorld *__newtonW, irr::scene::ISceneManager *__sceneManager, int __id,
		irr::core::vector3df __position, irr::video::SColorf __color, irr::f32 __radius) :
			base::SceneObjects(__sceneManager, __newtonW, this, __id){

	_light = _sceneManager->addLightSceneNode(0, __position, __color, __radius, __id);

	setPosition(__position.X, __position.Y, __position.Z);

	_light->setID(getId());
}

void base::FrameLight::createLight(irr::core::vector3df __position, irr::video::SColorf __color, irr::f32 __radius){
	_light = _sceneManager->addLightSceneNode(0, __position, __color, __radius, getId());

	setPosition(__position.X, __position.Y, __position.Z);
}

void base::FrameLight::repaint(){
	_light->setPosition(_position);
}

void base::FrameLight::drop(){
	dropObject();
}

void base::FrameLight::enableCastShadow(bool __enable){
	_light->enableCastShadow(__enable);
}

void base::FrameLight::setLightData(irr::video::SLight __color){
	_light->setLightData(__color);
}

void base::FrameLight::setLightType(irr::video::E_LIGHT_TYPE __type){
	_light->setLightType(__type);
}

void base::FrameLight::setVisible(bool __visible){
	_light->setVisible(__visible);
}

void base::FrameLight::setRadius(irr::f32 __radius){
	_light->setRadius(__radius);
}

irr::scene::ILightSceneNode* base::FrameLight::getLightSceneNode(){
	return _light;
}

irr::scene::ISceneNode* base::FrameLight::getSceneNode(){
	return dynamic_cast<irr::scene::ISceneNode*>(_light);
}
