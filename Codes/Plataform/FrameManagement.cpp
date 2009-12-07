/*
 * FrameManagement.cpp
 *
 *  Created on: 18/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/FrameManagement.h"
#include <iostream>

using namespace plataform;
using namespace GenericList;

FrameManagement::FrameManagement(int __width, int __heigth, int __bitsPerPixel,
		bool __fullScreen, bool __stencilBuffer){

	_baseFrame = new base::Frame(__width, __heigth, __bitsPerPixel, __fullScreen, __stencilBuffer);
	_baseFrame->addFontFrame("fonts/font800.xml");
	_baseFrame->setTitleFrame(L"..::Snake 3D - By: Henrique Jonas::..");
	_baseFrame->setColor(0,0,0,0);

	_baseFrame->getGUIEnviroment()->loadGUI("xmlgui/guiMainMenu.xml", 0);

}

base::Frame* FrameManagement::getBaseFrame(){
	return _baseFrame;
}
