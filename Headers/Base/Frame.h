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

#include "../Events/WrapperEvent.h"

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
            
        public:

            Frame();
            Frame(Frame *__frame);
            Frame(int __width, int __heigth, int __bitsPerPixel, bool __fullScreen, bool __stencilBuffer);

            void setDevice(irr::IrrlichtDevice *__device);
            void setVideoDriver(irr::video::IVideoDriver *__driver);
            void setGUIEnviroment(irr::gui::IGUIEnvironment *__guiEnv);
            void setSceneManager(irr::scene::ISceneManager *__scene);

            void setFont(const irr::c8* __filename, FrameFont *__font);
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

            irr::video::ITexture* getImage(const irr::c8* __filename);

            int getFPS();

            bool frameRun();
            bool windowActive();
            void drawFrame();
            void closeFrame();

            irr::scene::IAnimatedMeshSceneNode* addAnimetedSceneNode(const irr::c8* __filename);

            irr::gui::IGUIButton* addButton(const irr::core::rect<irr::s32>& __rectangle, irr::gui::IGUIElement* __parent,
                                    irr::s32 __id, const wchar_t* __text, const wchar_t* __tooltiptext);

            irr::scene::ICameraSceneNode* addCameraFPS(irr::scene::ISceneNode* __parent,
                                    irr::f32 __rotateSpeed, irr::f32 __moveSpeed, irr::s32 __id,
                                    irr::SKeyMap* __keyMapArray, irr::s32 __keyMapSize, bool __noVerticalMovement,
                                    irr::f32 __jumpSpeed);

            irr::gui::IGUIStaticText* addText(const wchar_t *__text, const irr::core::rect<irr::s32> __rectangle, bool __border,
									bool __worldWrapper, irr::gui::IGUIElement *__parent, irr::s32 __id, bool __fillBackground);

            irr::scene::ICameraSceneNode* addCameraMaya(irr::scene::ISceneNode* __parent,
                                    irr::f32 __rotateSpeed, irr::f32 __zoomSpeed,
                                    irr::f32 __translationSpeed, irr::s32 __id);

            irr::gui::IGUIFont* addFontFrame(const irr::c8* __filename);

            irr::gui::IGUIImage* addImage(const irr::c8* __filename, irr::core::position2d<irr::s32> __pos,
                                    bool __useAlphaChannel, irr::gui::IGUIElement* __parent, irr::s32 __id,
                                    const wchar_t* __text);

            irr::gui::IGUIFileOpenDialog* addOpenDialog(const wchar_t* __title,
                                    bool __modal, irr::gui::IGUIElement* __parent, irr::s32 __id);

            irr::gui::IGUIContextMenu* addMenu(irr::gui::IGUIElement *__parent, irr::s32 __id);

            irr::scene::ITerrainSceneNode* addTerrainSceneNode(const irr::c8* __filename, irr::scene::ISceneNode *__parent, irr::s32 __id,
									irr::core::vector3df __position, irr::core::vector3df __rotation,
									irr::core::vector3df __scale, irr::video::SColor __vertexColor,
									irr::s32 __maxLOD, irr::scene::E_TERRAIN_PATCH_SIZE __patchSize, irr::s32 __smoothFactor);

            irr::scene::ISceneNode* addSkyBox(const irr::c8* __textureUp, const irr::c8* __textureDown, const irr::c8* __textureLeft,
									const irr::c8* __textureRight, const irr::c8* __textureFt, const irr::c8* __textureBk,
									irr::scene::ISceneNode *__parent, irr::s32 __id);

            irr::scene::ITriangleSelector* addSelectorTerrainNode(irr::scene::ITerrainSceneNode *__node, irr::s32 __lod);

            irr::scene::ITriangleSelector* addSelectorNode(irr::scene::IMesh *__mesh, irr::scene::ISceneNode *__node);

            irr::scene::ISceneNodeAnimator* addColision(irr::scene::ITriangleSelector *__trianguleSelector, irr::scene::ISceneNode *__sceneNode,
									irr::core::vector3df __ellipsoidRadius, irr::core::vector3df __gravityPerSecond,
									irr::core::vector3df __ellipsoidTranslatio, irr::f32 __slidingValue);

    };
    

};



#endif	/* _FRAME_H */

