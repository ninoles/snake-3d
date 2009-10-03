#include "../../Headers/Context/SAppContext.h"

using namespace Context;

SAppContext::SAppContext(irr::IrrlichtDevice *__device){
	_device = __device;
}

SAppContext::SAppContext(){
	_device = 0;
}

void SAppContext::setDevice(irr::IrrlichtDevice* __device){
	_device = __device;
}

irr::IrrlichtDevice* SAppContext::getDevice(){
	return _device;
}

irr::gui::IGUIEnvironment* SAppContext::getEnvironment(){
	return _device->getGUIEnvironment();
}

irr::video::IVideoDriver* SAppContext::getDriver(){
	return _device->getVideoDriver();
}
	
