/*
 * InitialFrame.cpp
 *
 *  Created on: 12/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Plataform/InitalFrame.h"

using namespace plataform;

InitialFrame::InitialFrame(){
	initComponents();
}

void InitialFrame::initComponents(){

	_frame = new Frame(800, 600, 32, false, false);
	_frame->setTitleFrame(L"..::Snake 3D::..");
	_frame->setResizable(false);

	_frame->addFontFrame("/home/henrique/irrlicht-1.5.1/media/fontcourier.bmp");

	_menu = new FrameMenu(_frame->addMenu(0, 0));

	createMenu();
}

void InitialFrame::createMenu(){
	_menu->addItemMainMenu(L"Arquivo", 0, true, true, false);
	_menu->addItemMainMenu(L"Partidas", 0, true, true, false);
	_menu->addItemMainMenu(L"Pontos", 0, true, true, false);
	_menu->addItemMainMenu(L"Ajuda", 0, true, true, false);

	FrameMenu *subMenuArchive = new FrameMenu(_menu->addSubMenu(0));
	FrameMenu *subMenuMatches = new FrameMenu(_menu->addSubMenu(1));
	FrameMenu *subMenuPoints = new FrameMenu(_menu->addSubMenu(2));
	FrameMenu *subMenuHelp = new FrameMenu(_menu->addSubMenu(3));

	subMenuArchive->addItemMainMenu(L"Novo Jogo", Events::GUI_ID_NEW_GAME, true, false, false);
	subMenuArchive->addItemMainMenu(L"Carregar Jogo", Events::GUI_ID_LOAD_GAME, true, false, false);
	subMenuArchive->addItemMainMenu(L"Preferências", Events::GUI_ID_PREFERENCES_GAME, true, false, false);
	subMenuArchive->addItemMainMenu(L"Sair", Events::GUI_ID_QUIT, true, false, false);

	subMenuMatches->addItemMainMenu(L"Melhores Jogadores", Events::GUI_ID_BEST_PLAYERS, true, false, false);
	subMenuMatches->addItemMainMenu(L"Partidas Disputadas", Events::GUI_ID_MATCHES, true, false, false);

	subMenuPoints->addItemMainMenu(L"Maiores Pontuações", Events::GUI_ID_POINT_PLAYERS, true, false, false);
	subMenuPoints->addItemMainMenu(L"Melhores em Pontos e Partidas", Events::GUI_ID_WIN_PLAYERS, true, false, false);

	subMenuHelp->addItemMainMenu(L"Ajuda", Events::GUI_ID_INSTRUCTIONS, true, false, false);
	subMenuHelp->addItemMainMenu(L"Sobre", Events::GUI_ID_ABOUT, true, false, false);
}

void InitialFrame::displayFrame(bool __visible){

	if(__visible)
		_frame->drawFrame();
	else
		_frame->closeFrame();

}

Frame* InitialFrame::getFrame(){
	return _frame;
}
