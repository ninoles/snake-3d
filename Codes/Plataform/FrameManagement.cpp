/*
 * FrameManagement.cpp
 *
 *  Created on: 18/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/FrameManagement.h"

platform::FrameManagement::FrameManagement(int __width, int __heigth, int __bitsPerPixel, bool __fullScreen,
		bool __stencilBuffer, bool __activateJoystick, bool __antiAliasing){

	_frame = new base::Frame(__width, __heigth, __bitsPerPixel, __fullScreen, __stencilBuffer, __activateJoystick, __antiAliasing);
	_frame->addFontFrame("fonts/font800.xml");
	_frame->setTitleFrame(L"->Snake 3D<-");
	_frame->setColor(0,0,0,0);

	_frame->getGUIEnviroment()->loadGUI("xmlgui/guiMainMenu.xml", 0);

}

void platform::FrameManagement::switchScreens(int __newScreen){
	file::ConfFrame *conf = new file::ConfFrame();
	conf->setArchiveRead("conf/config_video.xml");

	switch(__newScreen){

		case Events::GAME_LOAD_ARCHIVE_GAME:
			break;

		case Events::GAME_LOAD_ARCHIVE_HELP:
			break;

		case Events::GAME_LOAD_ARCHIVE_INFO_SCORE:
			break;

		case Events::GAME_SAVE_ARCHIVE_GAME:
			break;

		case Events::GAME_SAVE_ARCHIVE_PREF:
            _frame = new base::Frame(conf->readWidth(),conf->readHeigth(), conf->readBitsPerPixel(), conf->readFullScreen(),
					conf->readStencilBuffer(), conf->readActivateJoy(), conf->readAntiAliasing());
			break;

		case Events::GAME_LOAD_ARCHIVE_PREF:
			break;

		case Events::GAME_START_MATCH:
			break;

		case Events::GAME_NOTHING_OPTION:
			break;
	}

	_frame->getButtonEvents()->setGameOption(Events::GAME_NOTHING_OPTION);

	delete conf;
}

base::Frame* platform::FrameManagement::getBaseFrame(){
	return _frame;
}
