/* 
 * File:   Frame.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 22:03
 */

#ifndef _FRAME_H
#define	_FRAME_H

#include <irrlicht.h>
#include <time.h>

#include "../Events/WrapperEvent.h"

namespace base{

	enum idFrames{

		FRAME_ID_BASE = 1000,
		FRAME_ID_ABOUT,
		FRAME_ID_MAIN_MENU,
		FRAME_ID_NEW_GAME

	};

    class Frame{
        
        private:

            irr::IrrlichtDevice *_device;
            irr::video::IVideoDriver *_driver;
            irr::gui::IGUIEnvironment *_guiEnv;
            irr::scene::ISceneManager *_sceneMang;

            irr::video::SColor _colorFrame;
            irr::gui::IGUIFont *_font;

            Events::WrapperEvents *_eventReceiver;

            /*
             * Caracteristics of frame
             */
            int _width;
            int _heigth;
            int _bitsPerPixel;
            bool _fullscreen;
            bool _stencilBuffer;

        public:

            Frame();
            Frame(Frame *__frame);
            Frame(int __width, int __heigth, int __bitsPerPixel, bool __fullScreen, bool __stencilBuffer);

            void setDevice(irr::IrrlichtDevice *__device);
            void setVideoDriver(irr::video::IVideoDriver *__driver);
            void setGUIEnviroment(irr::gui::IGUIEnvironment *__guiEnv);
            void setSceneManager(irr::scene::ISceneManager *__scene);

            void setFont(const irr::c8* __filename);
            void setModeCursor(bool __visible);
            void setEventReceiver(Events::WrapperEvents *__eventReceiver);
            void setTitleFrame(const wchar_t* __titleFrame);
            void setResizable(bool __resizable);
            void setColor(int __alpha, int __red, int __green, int __blue);

            irr::IrrlichtDevice* getDevice();
            irr::video::IVideoDriver* getVideoDriver();
            irr::gui::IGUIEnvironment* getGUIEnviroment();
            irr::scene::ISceneManager* getSceneManager();
            irr::gui::IGUIFont *getFont();
            irr::video::SColor getColorFrame();

            Events::WrapperEvents* getEventReceiver();

            irr::video::ITexture* getImage(const irr::c8* __filename);

            int getFPS();

            bool frameRun();
            bool windowActive();
            void drawFrame();
            void closeFrame();

            int getWidth();
            int getHeigth();
            int getBitsPerPixel();
            bool isFullScreen();
            bool isStencilBuffer();

            irr::gui::IGUIButton* addButton(const irr::core::rect<irr::s32>& __rectangle, irr::gui::IGUIElement* __parent,
                                    irr::s32 __id, const wchar_t* __text, const wchar_t* __tooltiptext);

            irr::gui::IGUIStaticText* addText(const wchar_t *__text, const irr::core::rect<irr::s32> __rectangle, bool __border,
									bool __worldWrapper, irr::gui::IGUIElement *__parent, irr::s32 __id, bool __fillBackground);

            irr::gui::IGUIFont* addFontFrame(const irr::c8* __filename);

            irr::gui::IGUIImage* addImage(const irr::c8* __filename, irr::core::position2d<irr::s32> __pos,
                                    bool __useAlphaChannel, irr::gui::IGUIElement* __parent, irr::s32 __id,
                                    const wchar_t* __text);

            irr::gui::IGUIFileOpenDialog* addOpenDialog(const wchar_t* __title,
                                    bool __modal, irr::gui::IGUIElement* __parent, irr::s32 __id);

            irr::gui::IGUIContextMenu* addMenu(irr::gui::IGUIElement *__parent, irr::s32 __id);

    };
    
};

#endif	/* _FRAME_H */
