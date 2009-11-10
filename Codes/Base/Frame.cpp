#include "../../Headers/Base/Frame.h"

using namespace base;
using namespace Context;
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

	_device = irr::createDevice(irr::video::EDT_OPENGL,
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

void Frame::setFont(const irr::c8* __filename, FrameFont *__font) {
	__font->setFont(_guiEnv->getFont(__filename));
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

irr::scene::IAnimatedMeshSceneNode* Frame::addAnimetedSceneNode(
		const irr::c8* __filename) {

	return _sceneMang->addAnimatedMeshSceneNode(_sceneMang->getMesh(__filename));
}

irr::gui::IGUIStaticText* Frame::addText(const wchar_t *__text,
		const irr::core::rect<irr::s32> __rectangle, bool __border,
		bool __worldWrapper, irr::gui::IGUIElement *__parent, irr::s32 __id,
		bool __fillBackground) {

	return _guiEnv->addStaticText(__text, __rectangle, __border,
			__worldWrapper, __parent, __id, __fillBackground);
}

irr::scene::ICameraSceneNode* Frame::addCameraFPS(
		irr::scene::ISceneNode* __parent, irr::f32 __rotateSpeed,
		irr::f32 __moveSpeed, irr::s32 __id, irr::SKeyMap* __keyMapArray,
		irr::s32 __keyMapSize, bool __noVerticalMovement, irr::f32 __jumpSpeed) {

	return _sceneMang->addCameraSceneNodeFPS(__parent, __rotateSpeed,
			__moveSpeed, __id, __keyMapArray, __keyMapSize,
			__noVerticalMovement, __jumpSpeed);
}

irr::scene::ICameraSceneNode* Frame::addCameraMaya(
		irr::scene::ISceneNode* __parent, irr::f32 __rotateSpeed,
		irr::f32 __zoomSpeed, irr::f32 __translationSpeed, irr::s32 __id) {

	return _sceneMang->addCameraSceneNodeMaya(__parent, __rotateSpeed,
			__zoomSpeed, __translationSpeed, __id);
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

irr::scene::ITerrainSceneNode* Frame::addTerrainSceneNode(
		const irr::c8* __filename, irr::scene::ISceneNode *__parent,
		irr::s32 __id, irr::core::vector3df __position,
		irr::core::vector3df __rotation, irr::core::vector3df __scale,
		irr::video::SColor __vertexColor, irr::s32 __maxLOD,
		irr::scene::E_TERRAIN_PATCH_SIZE __patchSize, irr::s32 __smoothFactor) {

	return _sceneMang->addTerrainSceneNode(__filename, __parent, __id,
			__position, __rotation, __scale, __vertexColor, __maxLOD,
			__patchSize, __smoothFactor);
}

irr::scene::ISceneNode* Frame::addSkyBox(const irr::c8* __textureUp,
		const irr::c8* __textureDown, const irr::c8* __textureLeft,
		const irr::c8* __textureRight, const irr::c8* __textureFt,
		const irr::c8* __textureBk, irr::scene::ISceneNode *__parent,
		irr::s32 __id) {

	return _sceneMang->addSkyBoxSceneNode(_driver->getTexture(__textureUp),
			_driver->getTexture(__textureDown), _driver->getTexture(
					__textureLeft), _driver->getTexture(__textureRight),
			_driver->getTexture(__textureFt), _driver->getTexture(__textureBk),
			__parent, __id);
}

irr::scene::ITriangleSelector* Frame::addSelectorNode(
		irr::scene::IMesh *__mesh, irr::scene::ISceneNode *__node) {
	irr::scene::ITriangleSelector *selector =
			_sceneMang->createTriangleSelector(__mesh, __node);

	__node->setTriangleSelector(selector);

	return selector;
}

irr::scene::ITriangleSelector* Frame::addSelectorTerrainNode(
		irr::scene::ITerrainSceneNode *__node, irr::s32 __lod) {
	irr::scene::ITriangleSelector *selector =
			_sceneMang->createTerrainTriangleSelector(__node, __lod);

	__node->setTriangleSelector(selector);

	return selector;
}

irr::scene::ISceneNodeAnimator* Frame::addColision(
		irr::scene::ITriangleSelector *__trianguleSelector,
		irr::scene::ISceneNode *__sceneNode,
		irr::core::vector3df __ellipsoidRadius,
		irr::core::vector3df __gravityPerSecond,
		irr::core::vector3df __ellipsoidTranslatio, irr::f32 __slidingValue) {

	irr::scene::ISceneNodeAnimator *anim =
			_sceneMang->createCollisionResponseAnimator(__trianguleSelector,
					__sceneNode, __ellipsoidRadius, __gravityPerSecond,
					__ellipsoidTranslatio, __slidingValue);

	__trianguleSelector->drop();
	__sceneNode->addAnimator(anim);

	return anim;
}

