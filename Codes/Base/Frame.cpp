/*
 * File:   Frame.cpp
 * Author: Henrique Jonas
 *
 * Created on 3 de Outubro de 2009, 22:03
 */

#include "../../Headers/Base/Frame.h"

base::Frame::Frame(int __width, int __heigth, int __bitsPerPixel, bool __fullScreen,
		bool __stencilBuffer, bool __activateJoystick, bool __antiAliasing) {

	_width = __width;
	_heigth = __heigth;
	_bitsPerPixel = __bitsPerPixel;
	_fullscreen = __fullScreen;
	_stencilBuffer = _stencilBuffer;
	_activateJoystick = __activateJoystick;
	_antiAliasing = _antiAliasing;

	_device = irr::createDevice(irr::video::EDT_SOFTWARE,
			irr::core::dimension2d<irr::s32>(__width, __heigth),
			__bitsPerPixel, __fullScreen, _stencilBuffer, false, 0);

	if (_device == 0)
		return;

	_eventReceiver = new Events::WrapperEvents(_device);
	_eventReceiver->setAllEvents();

	_device->setEventReceiver(_eventReceiver);

	_driver = _device->getVideoDriver();
	_guiEnv = _device->getGUIEnvironment();
	_sceneMang = _device->getSceneManager();

}

irr::IrrlichtDevice* base::Frame::getDevice() {
	return _device;
}

irr::video::IVideoDriver* base::Frame::getVideoDriver() {
	return _driver;
}

irr::gui::IGUIEnvironment* base::Frame::getGUIEnviroment() {
	return _guiEnv;
}

irr::scene::ISceneManager* base::Frame::getSceneManager() {
	return _sceneMang;
}

irr::gui::IGUIFont* base::Frame::getFont(){
	return _font;
}

irr::video::SColor base::Frame::getColorFrame(){
	return _colorFrame;
}

Events::NodeMoviment* base::Frame::getNodeMoviment(){
	return _eventReceiver->getNodeMoviment();
}

Events::ButtonEvents* base::Frame::getButtonEvents(){
	return _eventReceiver->getButtonEvents();
}

void base::Frame::setEventReceiver(Events::WrapperEvents *__eventReceiver) {
	_eventReceiver = __eventReceiver;
}

void base::Frame::setFont(const irr::c8* __filename) {
	_guiEnv->getFont(__filename);
}

void base::Frame::setModeCursor(bool __visible) {
	_device->getCursorControl()->setVisible(__visible);
}

void base::Frame::setResizable(bool __resizable) {
	_device->setResizeAble(__resizable);
}

void base::Frame::setTitleFrame(const wchar_t* __titleFrame) {
	_device->setWindowCaption(__titleFrame);
}

int base::Frame::getFPS() {
	return _driver->getFPS();
}

void base::Frame::setColor(int __alpha, int __red, int __green, int __blue) {
	_colorFrame.set(__alpha, __red, __green, __blue);
}

int base::Frame::getWidth(){
	return _width;
}

int base::Frame::getHeigth(){
	return _heigth;
}

int base::Frame::getBitsPerPixel(){
	return _bitsPerPixel;
}

bool base::Frame::isFullScreen(){
	return _fullscreen;
}

bool base::Frame::isStencilBuffer(){
	return _stencilBuffer;
}

bool base::Frame::isAntiAliasing(){
	return _antiAliasing;
}

bool base::Frame::isJoystick(){
	return _activateJoystick;
}

void base::Frame::repaint(int __width, int __heigth, int __bitsPerPixel, bool __fullScreen,
		bool __stencilBuffer, bool __activateJoystick, bool __antiAliasing){

	drop();

	_width = __width;
	_heigth = __heigth;
	_bitsPerPixel = __bitsPerPixel;
	_fullscreen = __fullScreen;
	_stencilBuffer = _stencilBuffer;
	_activateJoystick = __activateJoystick;
	_antiAliasing = _antiAliasing;

	_device = irr::createDevice(irr::video::EDT_SOFTWARE,
			irr::core::dimension2d<irr::s32>(__width, __heigth),
			__bitsPerPixel, __fullScreen, __stencilBuffer, false, 0);

	if (_device == 0)
		return;
}

void base::Frame::show(){
    _driver->beginScene(true, true, 0);
	_sceneMang->drawAll();
	_guiEnv->drawAll();
	_driver->endScene();
}

void base::Frame::drop(){
	_device->drop();
}

bool base::Frame::isVisible(){
    return _device->run();
}

irr::video::ITexture* base::Frame::getTexture(const irr::c8* __filename){
	return _driver->getTexture(__filename);
}

irr::gui::IGUIButton * base::Frame::addButton(
		const irr::core::rect<irr::s32>& __rectangle,
		irr::gui::IGUIElement* __parent, irr::s32 __id, const wchar_t* __text,
		const wchar_t* __tooltiptext) {

	return _guiEnv->addButton(__rectangle, __parent, __id, __text,
			__tooltiptext);
}

irr::gui::IGUIStaticText* base::Frame::addText(const wchar_t *__text,
		const irr::core::rect<irr::s32> __rectangle, bool __border,
		bool __worldWrapper, irr::gui::IGUIElement *__parent, irr::s32 __id,
		bool __fillBackground) {

	return _guiEnv->addStaticText(__text, __rectangle, __border,
			__worldWrapper, __parent, __id, __fillBackground);
}

irr::gui::IGUIFont * base::Frame::addFontFrame(const irr::c8* __filename) {

	irr::gui::IGUISkin* skin = _guiEnv->getSkin();
	irr::gui::IGUIFont* font = _guiEnv->getFont(__filename);

	if (font)
		skin->setFont(font);

	return font;
}

irr::gui::IGUIImage* base::Frame::addImage(const irr::c8* __filename,
		irr::core::position2d<irr::s32> __pos, bool __useAlphaChannel,
		irr::gui::IGUIElement* __parent, irr::s32 __id, const wchar_t* __text) {

	return _guiEnv->addImage(_driver->getTexture(__filename), __pos,
			__useAlphaChannel, __parent, __id, __text);
}

irr::gui::IGUIFileOpenDialog* base::Frame::addOpenDialog(const wchar_t* __title,
		bool __modal, irr::gui::IGUIElement* __parent, irr::s32 __id) {

	return _guiEnv->addFileOpenDialog(__title, __modal, __parent, __id);
}

irr::gui::IGUIContextMenu* base::Frame::addMenu(irr::gui::IGUIElement *__parent,
		irr::s32 __id) {
	return _guiEnv->addMenu();
}
