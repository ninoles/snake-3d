#include "../../Headers/Base/Frame.h"

using namespace base;
using namespace Context;
using namespace Events;
Frame::Frame(){
    _device = 0;
}

Frame::Frame(irr::video::E_DRIVER_TYPE __driverType, int __width, int __heigth, bool __fullScreen, int __bitsPerPixel, bool __stencilBuffer){
    _device = irr::createDevice(__driverType, irr::core::dimension2d<irr::s32>(__width, __heigth),
                            __bitsPerPixel, __fullScreen, __stencilBuffer, false, 0);

    
    _context->setDevice(_device);
    _eventReceiver = new WrapperEvents(_context);
    
    _driver = _device->getVideoDriver();
    _guiEnv = _device->getGUIEnvironment();
    _sceneMang = _device->getSceneManager();
}

void Frame::setEventReceiver(Events::WrapperEvents *__eventReceiver){
    _eventReceiver = __eventReceiver;
}

void Frame::setFont(const irr::c8* __filename, FrameFont *__font){
    __font->setFont(_guiEnv->getFont(__filename));
}

void Frame::setModeCursor(bool __visible){
    _device->getCursorControl()->setVisible(__visible);
}

void Frame::setResizable(bool __resizable){
    _device->setResizeAble(__resizable);
}

void Frame::setTitleFrame(const wchar_t* __titleFrame){
    _device->setWindowCaption(__titleFrame);
}




