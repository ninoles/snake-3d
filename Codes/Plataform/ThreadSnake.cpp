/*
 * Thread.cpp
 *
 *  Created on: 04/01/2010
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/ThreadSnake.h"

pthread_mutex_t _mutex;
Events::KeyBoardEvents  keyEvent;

void* snakeForward(void* __snake){
	platform::Snake* snake = (platform::Snake*)__snake;

	while(true){
		sleepms(65);
		pthread_mutex_lock(&_mutex);
		snake->snakeForward();
		pthread_mutex_unlock(&_mutex);
	}

	pthread_exit(NULL);
}

void* turnSnake(void* __snake){
	platform::Snake* snake = (platform::Snake*)__snake;
	irr::EKEY_CODE keyCode;


	while(true){

		keyCode = Events::NodeMoviment::_currentMoviment;

		if(keyCode == snake->getMovimentLeft() || keyCode == snake->getMovimentRight()){

			pthread_mutex_lock(&_mutex);

			sleepms(500);

			Events::NodeMoviment::_currentMoviment = irr::KEY_KEY_0;

			if(keyCode == snake->getMovimentLeft())
				snake->turnLeft();

			else if(keyCode == snake->getMovimentRight())
				snake->turnRight();

			pthread_mutex_unlock(&_mutex);

		}

	}

	pthread_exit(NULL);
}

platform::ThreadSnake::ThreadSnake(){

	srand(time(NULL));
	_idThread = rand();

	sleepms(500); //Waiting time for the rand() function correctly.

}

void platform::ThreadSnake::createThread(platform::Snake *__arg){
	int validate_1 = -1,
		validate_2 = -1;

	validate_1 = pthread_create(&_threadRun, NULL, snakeForward, __arg);
	validate_2 = pthread_create(&_threadTurn, NULL, turnSnake, __arg);

	pthread_mutex_init(&_mutex, NULL);

	if(validate_1 == validate_2)
		std::cerr << "A thread on the player is running successfully." << std::endl;
	else
		std::cerr << "A thread on the player has a problem. The application will be aborted." << std::endl;

}

void platform::ThreadSnake::pauseThread(){

}

void platform::ThreadSnake::stopThread(){

	pthread_cancel(_threadRun);
	pthread_cancel(_threadTurn);

	int validate_1 = pthread_detach(_threadRun);
	int validate_2 = pthread_detach(_threadTurn);

	if(validate_1 == validate_2)
		std::cerr << "The threads number: " << _idThread << " was stopped successfully" << std::endl;
	else
		std::cerr << "The threads number: " << _idThread << " was not stopped successfully" << std::endl;

}

int platform::ThreadSnake::getID(){
	return _idThread;
}
