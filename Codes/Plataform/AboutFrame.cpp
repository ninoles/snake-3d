/*
 * AboutFrame.cpp
 *
 *  Created on: 12/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Plataform/AboutFrame.h"

using namespace plataform;

AboutFrame::AboutFrame(){

	initComponents();

}

void AboutFrame::initComponents(){

	_frame = new Frame(398, 298, 32, false, false);

	_frame->setTitleFrame(L"Sobre Snake 3D");
	_frame->setResizable(false);
	_frame->addFontFrame("/home/henrique/irrlicht-1.5.1/media/fontcourier.bmp");

	_backGround = new FrameImage(_frame->addImage("/home/henrique/Desktop/Snake Project/snake-3d/images/aboutbox.jpg", irr::core::position2d<irr::s32>(0, 0), false, 0, 0, L""));

	_closeWindow = new FrameButton(_frame->addButton(irr::core::rect<irr::s32>(150, 240, 250, 240 + 20), 0, Events::GUI_ID_CLOSE_FRAME, L"Fechar", L"Fechar janela"));
}

void AboutFrame::displayFrame(bool __visible){

	if(__visible)
		_frame->drawFrame();
	else
		_frame->closeFrame();

}

Frame* AboutFrame::getFrame(){
	return _frame;
}

