/*
 * Game.cpp
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Plataform/Game.h"

using namespace plataform;

Game::Game(){

	//Implementar aqui o carregamento do arquivo de configuração do jogo.

	_frameMan = new FrameManagement(800, 600, 32, false, true);

}

void Game::run(){

	while(_frameMan->getBaseFrame()->frameRun())
		_frameMan->getBaseFrame()->drawFrame();

}

