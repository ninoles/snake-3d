/*
 * GamePlay.cpp
 *
 *  Created on: 07/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Physis/Gameplay.h"

using namespace physis;
using namespace irr;
using namespace std;

Gameplay::Gameplay(scene::ISceneManager *__sceneManagement){
	_sceneManagement = __sceneManagement;

	_newtonW = NewtonCreate();

	NewtonSetSolverModel(_newtonW, 1);
}

Gameplay::Gameplay(){
	_newtonW = NewtonCreate();

	NewtonSetSolverModel(_newtonW, 1);
}

void Gameplay::checkForCollisions(base::FrameAnimatedNode* __nodeA, base::FrameAnimatedNode* __nodeB){

	//Matrix to store FrameSceneNode position
	core::matrix4 matrixA, matrixB;

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

NewtonWorld* Gameplay::getNewtonWorld(){
	return _newtonW;
}

/*
 * This method is deprecated
 *
bool Gameplay::checkForCollisions(int numberOfNodes, ...){

	int idNode;

	va_list list;
	va_start(list, numberOfNodes);

	idNode = va_arg(list, int);

	return false;
}*/

