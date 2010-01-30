/*
 * GamePlay.cpp
 *
 *  Created on: 07/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Gameplay.h"

platform::Gameplay::Gameplay(irr::scene::ISceneManager *__sceneManagement, irr::video::IVideoDriver *__driver){
	_sceneManagement = __sceneManagement;
	_driver = __driver;
	_newtonW = NewtonCreate();
	_match = new Match();

	NewtonSetSolverModel(_newtonW, 0);
}

void platform::Gameplay::initMatch(){
	_match->initMatch(_driver, _sceneManagement, _newtonW);
	_match->getMap()->initMaps(_sceneManagement, _driver, _newtonW);
}

void platform::Gameplay::randomMap(){
	_match->getMap()->generateRandomMap();
	_match->getMap()->loadSkyBox();
}

void platform::Gameplay::checkCollisionToPoint(){

}

void platform::Gameplay::run(){
	_match->runMatch();
	splitScreenForPlayers();
}

void platform::Gameplay::checkForCollisions(base::FrameAnimatedNode* __nodeA, base::FrameAnimatedNode* __nodeB){

	//Matrix to store FrameAnimatedNode position
	irr::core::matrix4 matrixA, matrixB;

	//Copy position
	matrixA.makeIdentity();
	matrixB.makeIdentity();

	matrixA.setTranslation(__nodeA->getSceneNode()->getPosition());
	matrixB.setTranslation(__nodeB->getSceneNode()->getPosition());

	contacts nContacts;
	normals nNormals;
	penetration nPenetration;

	int numberHits = NewtonCollisionCollide(_newtonW, NUMBER_CONTACTS, __nodeA->getPhysisNode()->getMeshCollision()->getCollisionNode(), (float*)&matrixA[0],
			__nodeB->getPhysisNode()->getMeshCollision()->getCollisionNode(), (float*)&matrixB[0], nContacts, nNormals, nPenetration, 0);

	if(numberHits > 0){
		__nodeA->_movimentNode = false;
		__nodeB->_movimentNode = false;
	} else {
		__nodeA->_movimentNode = true;
		__nodeB->_movimentNode = true;
	}

}

void platform::Gameplay::splitScreenForPlayers(){

	if(_match->getGroupPlayers()->getNumberOfPlayers() > 1){

		_sceneManagement->setActiveCamera(_match->getGroupPlayers()->getAllPlayers()->get(0).getSnake()->getCamera()->getCamera());
		_driver->setViewPort(irr::core::rect<irr::s32>(0,0,_driver->getScreenSize().Width, _driver->getScreenSize().Height/2));
		_sceneManagement->drawAll();

		_sceneManagement->setActiveCamera(_match->getGroupPlayers()->getAllPlayers()->get(1).getSnake()->getCamera()->getCamera());
		_driver->setViewPort(irr::core::rect<irr::s32>(0,_driver->getScreenSize().Height/2,_driver->getScreenSize().Width, _driver->getScreenSize().Height));
	}

}

NewtonWorld* platform::Gameplay::getNewtonWorld(){
	return _newtonW;
}

platform::Match* platform::Gameplay::getMatch(){
	return _match;
}
