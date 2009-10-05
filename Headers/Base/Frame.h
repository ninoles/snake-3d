/* 
 * File:   Frame.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 22:03
 */

#ifndef _FRAME_H
#define	_FRAME_H

#include <irrlicht.h>
#include <string>

#include "../Context/SAppContext.h"
#include "../Events/WrapperEvent.h"
#include "../Context/SAppContext.h"

#include "FrameCameraMaya.h"
#include "FrameFont.h"
#include "FrameAnimatedNode.h"
#include "FrameSceneNode.h"
#include "FrameButton.h"
#include "FrameCameraFPS.h"
#include "FrameOpenDialog.h"
#include "FrameImage.h"
#include "FrameMenu.h"

namespace base{

    class Frame{
        
        private:

            irr::IrrlichtDevice *_device;
            irr::video::IVideoDriver *_driver;
            irr::gui::IGUIEnvironment *_guiEnv;
            irr::scene::ISceneManager *_sceneMang;
            irr::gui::IGUIFont *_font;
            Events::WrapperEvents *_eventReceiver;
            Context::SAppContext *_context;
            
        public:

            Frame();
            Frame(irr::video::E_DRIVER_TYPE __driverType, int __width, int __heigth, bool __fullScreen, int __bitsPerPixel, bool __stencilBuffer);

            void setFont(const irr::c8* __filename, FrameFont *__font);
            void setModeCursor(bool __visible);
            void setEventReceiver(Events::WrapperEvents *__eventReceiver);
            void setTitleFrame(const wchar_t* __titleFrame);
            void setResizable(bool __resizable);

            irr::IrrlichtDevice* getDevice();
            irr::video::IVideoDriver* getVideoDriver();
            irr::gui::IGUIEnvironment* getGUIEnviroment();
            irr::scene::ISceneManager* getSceneManager();

            int getFPS();

            irr::scene::IAnimatedMeshSceneNode* addAnimetedSceneNode(std::string __absoluteWay);

            irr::gui::IGUIButton* addButton(const irr::core::rect<irr::s32>& __rectangle, irr::gui::IGUIElement* __parent,
                                    irr::s32 __id, const wchar_t* __text, const wchar_t* __tooltiptext);

            irr::scene::ISceneNodeAnimatorCameraFPS* addCameraFPS(irr::scene::ISceneNode* __parent,
                                    irr::f32 __rotateSpeed, irr::f32 __moveSpeed, irr::s32 __id,
                                    irr::SKeyMap* __keyMapArray, irr::s32 keyMapSize, bool __noVerticalMovement,
                                    irr::f32 __jumpSpeed);

            irr::scene::ISceneNodeAnimatorCameraMaya* addCameraMaya(irr::scene::ISceneNode* __parent,
                                    irr::f32 __rotateSpeed, irr::f32 __zoomSpeed,
                                    irr::f32 __translationSpeed, irr::s32 __id);

            irr::gui::IGUIFont* addFontFrame(const irr::c8* __filename);

            irr::gui::IGUIImage* addImage(std::string __filename, irr::core::position2d<irr::s32> __pos,
                                    bool __useAlphaChannel, irr::gui::IGUIElement* __parent, irr::s32 __id,
                                    const wchar_t* __text);

            irr::gui::IGUIFileOpenDialog* addOpenDialog(const wchar_t* __title,
                                    bool __modal, irr::gui::IGUIElement* __parent, irr::s32 __id);

            FrameMenu* addMenu();

    };
    

};



#endif	/* _FRAME_H */

