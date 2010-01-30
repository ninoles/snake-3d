/*
 * ThreadMatch.cpp
 *
 *  Created on: 26/01/2010
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/ThreadMatch.h"

void* pointManagement(void *__game){

	platform::Gameplay* game = (platform::Gameplay*)__game;

	while(true){
		game->getMatch()->randomPoints();
	}

	pthread_exit(NULL);

}

void* checkForCollision(void *__game){

	while(true){

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
		std::cerr << "The threads number: " << _idThread << " was stopped successfully" << std::endl;
	else
		std::cerr << "The threads number: " << _idThread << " was not stopped successfully" << std::endl;

}

void platform::ThreadMatch::pauseThread(){

}

int platform::ThreadMatch::getID(){
	return _idThread;
}

