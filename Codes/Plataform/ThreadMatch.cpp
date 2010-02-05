/*
 * ThreadMatch.cpp
 *
 *  Created on: 26/01/2010
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/ThreadMatch.h"
#include <iostream>

pthread_mutex_t mutex;

void* pointManagement(void *__game){

	platform::Gameplay* game = (platform::Gameplay*)__game;

	while(!game->run()){
		if(!Events::WrapperEvents::_isPaused)
			if(!game->getMatch()->isVisiblePoint())
				game->getMatch()->randomPoints();
	}

	pthread_exit(NULL);

}

void* checkForCollision(void *__game){

	platform::Gameplay* game = (platform::Gameplay*)__game;

	while(!game->run()){
		if(!Events::WrapperEvents::_isPaused)
			for(int k = 0; k < game->getMatch()->getGroupPlayers()->getNumberOfPlayers(); k++)
				if(game->checkCollisionToPoint(game->getMatch()->getPoint(), game->getMatch()->getGroupPlayers()->getAllPlayers()->get(k).getSnake())){
					game->insertPointToPlayer(k);
					game->getMatch()->setVisiblePoint(false);
				}
	}

	pthread_exit(NULL);

}

platform::ThreadMatch::ThreadMatch(){

	srand(time(NULL));
	_idThread = rand();

	sleepms(500); //Waiting time for the rand() function correctly.

}

void platform::ThreadMatch::createThread(platform::Gameplay *__arg){

	int validate_1 = -1,
		validate_2 = -1;

	validate_1 = pthread_create(&_threadPoint, NULL, pointManagement, __arg);
	validate_2 = pthread_create(&_threadCollision, NULL, checkForCollision, __arg);

	pthread_mutex_init(&mutex, NULL);

	if(validate_1 == validate_2)
		std::cerr << "A thread on the game is running successfully." << std::endl;
	else
		std::cerr << "A thread on the game has a problem. The application will be aborted." << std::endl;

}

void platform::ThreadMatch::stopThread(){

	pthread_cancel(_threadPoint);
	pthread_cancel(_threadCollision);

	int validate_1 = pthread_detach(_threadPoint);
	int validate_2 = pthread_detach(_threadCollision);

	if(validate_1 == validate_2)
		std::cerr << "The threads on the game was stopped successfully" << std::endl;
	else
		std::cerr << "A thread on the game has a problem. The application will be aborted." << std::endl;

}

void platform::ThreadMatch::pauseThread(){

}

int platform::ThreadMatch::getID(){
	return _idThread;
}

