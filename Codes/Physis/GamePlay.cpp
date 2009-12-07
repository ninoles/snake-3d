/*
 * GamePlay.cpp
 *
 *  Created on: 07/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Physis/Gameplay.h"

using namespace base;
using namespace GenericList;

using namespace physis;
using namespace irr;
using namespace std;

Gameplay::Gameplay(scene::ISceneManager *__sceneManagement){
	_sceneManagement = __sceneManagement;
	_nodes = new ArrayList<FrameSceneNode>();
}

Gameplay::Gameplay(){

}

void Gameplay::insertFrameNode(base::FrameSceneNode __valueNode){
	_nodes->add(__valueNode);
}

bool Gameplay::checkForCollisions(int numberOfNodes, ...){

	int idNode;

	va_list list;
	va_start(list, numberOfNodes);

	idNode = va_arg(list, int);

	return false;
}
