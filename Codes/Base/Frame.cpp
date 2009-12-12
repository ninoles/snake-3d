#include "../../Headers/Base/Frame.h"

using namespace base;
using namespace Events;

Frame::Frame() {
	_device = 0;
}

Frame::Frame(Frame *__frame) {

	_device = __frame->getDevice();
	_guiEnv = __frame->getGUIEnviroment();
	_sceneMang = __frame->getSceneManager();
	_font = __frame->getFont();
	_colorFrame = __frame->getColorFrame();

}

Frame::Frame(int __width, int __heigth, int __bitsPerPixel,
		bool __fullScreen, bool __stencilBuffer) {

	_width = __width;
	_heigth = __heigth;
	_bitsPerPixel = __bitsPerPixel;
	_fullscreen = __fullScreen;
	_stencilBuffer = _stencilBuffer;

	_device = irr::createDevice(irr::video::EDT_SOFTWARE,
			irr::core::dimension2d<irr::s32>(__width, __heigth),
			__bitsPerPixel, __fullScreen, __stencilBuffer, false, 0);

	if (_device == 0)
		return;

	_eventReceiver = new WrapperEvents(_device);
	_eventReceiver->setAllEvents();

	_device->setEventReceiver(_eventReceiver);

	_driver = _device->getVideoDriver();
	_guiEnv = _device->getGUIEnvironment();
	_sceneMang = _device->getSceneManager();

	_colorFrame.set(0, 200, 200, 200); //Color Default
}

void Frame::setDevice(irr::IrrlichtDevice *__device){
	_device = __device;
}

void Frame::setGUIEnviroment(irr::gui::IGUIEnvironment *__guiEnv){
	_guiEnv = __guiEnv;
}

void Frame::setSceneManager(irr::scene::ISceneManager *__scene){
	_sceneMang = __scene;
}

void Frame::setVideoDriver(irr::video::IVideoDriver *__driver){
	_driver = __driver;
}

irr::IrrlichtDevice* Frame::getDevice() {
	return _device;
}

irr::video::IVideoDriver* Frame::getVideoDriver() {
	return _driver;
}

irr::gui::IGUIEnvironment* Frame::getGUIEnviroment() {
	return _guiEnv;
}

irr::scene::ISceneManager* Frame::getSceneManager() {
	return _sceneMang;
}

irr::video::ITexture* Frame::getImage(const irr::c8* __filename) {
	return _driver->getTexture(__filename);
}

irr::gui::IGUIFont* Frame::getFont(){
	return _font;
}

irr::video::SColor Frame::getColorFrame(){
	return _colorFrame;
}

void Frame::setEventReceiver(Events::WrapperEvents *__eventReceiver) {
	_eventReceiver = __eventReceiver;
}

void Frame::setFont(const irr::c8* __filename) {
	_guiEnv->getFont(__filename);
}

void Frame::setModeCursor(bool __visible) {
	_device->getCursorControl()->setVisible(__visible);
}

void Frame::setResizable(bool __resizable) {
	_device->setResizeAble(__resizable);
}

void Frame::setTitleFrame(const wchar_t* __titleFrame) {
	_device->setWindowCaption(__titleFrame);
}

int Frame::getFPS() {
	return _driver->getFPS();
}

bool Frame::frameRun() {
	return _device->run();
}

bool Frame::windowActive() {
	return _device->isWindowActive();
}

void Frame::drawFrame() {
	_driver->beginScene(true, true, _colorFrame);
	_guiEnv->drawAll();
	_sceneMang->drawAll();

	_driver->endScene();
}

void Frame::setColor(int __alpha, int __red, int __green, int __blue) {
	_colorFrame.set(__alpha, __red, __green, __blue);
}

void Frame::closeFrame() {
	_device->drop();
}

int Frame::getWidth(){
	return _width;
}

int Frame::getHeigth(){
	return _heigth;
}

int Frame::getBitsPerPixel(){
	return _bitsPerPixel;
}

bool Frame::isFullScreen(){
	return _fullscreen;
}

bool Frame::isStencilBuffer(){
	return _stencilBuffer;
}

irr::gui::IGUIButton * Frame::addButton(
		const irr::core::rect<irr::s32>& __rectangle,
		irr::gui::IGUIElement* __parent, irr::s32 __id, const wchar_t* __text,
		const wchar_t* __tooltiptext) {

	return _guiEnv->addButton(__rectangle, __parent, __id, __text,
			__tooltiptext);
}

Events::WrapperEvents* Frame::getEventReceiver(){
	return _eventReceiver;
}

irr::gui::IGUIStaticText* Frame::addText(const wchar_t *__text,
		const irr::core::rect<irr::s32> __rectangle, bool __border,
		bool __worldWrapper, irr::gui::IGUIElement *__parent, irr::s32 __id,
		bool __fillBackground) {

	return _guiEnv->addStaticText(__text, __rectangle, __border,
			__worldWrapper, __parent, __id, __fillBackground);
}

irr::gui::IGUIFont * Frame::addFontFrame(const irr::c8* __filename) {

	irr::gui::IGUISkin* skin = _guiEnv->getSkin();
	irr::gui::IGUIFont* font = _guiEnv->getFont(__filename);

	if (font)
		skin->setFont(font);

	return font;
}

irr::gui::IGUIImage* Frame::addImage(const irr::c8* __filename,
		irr::core::position2d<irr::s32> __pos, bool __useAlphaChannel,
		irr::gui::IGUIElement* __parent, irr::s32 __id, const wchar_t* __text) {

	return _guiEnv->addImage(_driver->getTexture(__filename), __pos,
			__useAlphaChannel, __parent, __id, __text);
}

irr::gui::IGUIFileOpenDialog* Frame::addOpenDialog(const wchar_t* __title,
		bool __modal, irr::gui::IGUIElement* __parent, irr::s32 __id) {

	return _guiEnv->addFileOpenDialog(__title, __modal, __parent, __id);
}

irr::gui::IGUIContextMenu* Frame::addMenu(irr::gui::IGUIElement *__parent,
		irr::s32 __id) {
	return _guiEnv->addMenu();
}
