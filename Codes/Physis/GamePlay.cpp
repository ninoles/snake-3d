/*
 * GamePlay.cpp
 *
 *  Created on: 07/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Physis/Gameplay.h"

using namespace base;

using namespace physis;
using namespace irr;
using namespace std;

Gameplay::Gameplay(scene::ISceneManager *__sceneManagement){
	_sceneManagement = __sceneManagement;

	_newtonW = NewtonCreate(NULL,NULL);

	NewtonSetSolverModel(_newtonW, 1);
}

Gameplay::Gameplay(){
	_sceneManagement = NULL;

	_newtonW = NewtonCreate(NULL,NULL);

	NewtonSetSolverModel(_newtonW, 1);
}

bool Gameplay::checkForCollisions(FrameSceneNode __nodeA, FrameSceneNode __nodeB){

	//Matrix to store FrameSceneNode position
	core::matrix4 matrixA, matrixB;

	//Copy position
	matrixA.makeIdentity();
	matrixB.makeIdentity();

	matrixA.setTranslation(__nodeA.getSceneNode()->getPosition());
	matrixB.setTranslation(__nodeB.getSceneNode()->getPosition());

	contacts nContacts;
	normals nNormals;
	penetration nPenetration;

	int numberHits = NewtonCollisionCollide(_newtonW, NUMBER_CONTACTS, __nodeA.getCollision(), (float*)&matrixA[0],
			__nodeB.getCollision(), (float*)&matrixB[0], nContacts, nNormals, nPenetration, 0);

	return numberHits > 0;

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

