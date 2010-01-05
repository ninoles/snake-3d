/*
 * Thread.cpp
 *
 *  Created on: 04/01/2010
 *      Author: Henrique Jonas
 */

#include "../../Headers/Platform/Thread.h"

void* runSnake(void* __snake){
	platform::Snake* snake = (platform::Snake*)__snake;

	while(true){
		sleepms(80);
		snake->snakeForward();
	}

	pthread_exit(NULL);
}

void* checkCollisionMap(void* __gamePlay){

}

void* checkCollisionNode(void* __gamePlay){

}

void* checkCollisionPoint(void* __gamePlay){

}

platform::Thread::Thread(){

	srand(time(NULL));
	_idThread = rand();

	sleepms(500); //Waiting time for the rand() function correctly.

	std::cerr << "Thread - Generate ID: " << _idThread << std::endl;
}

void platform::Thread::createThread(platform::Snake *__arg){
	int validate = pthread_create(&_thread, NULL, runSnake, __arg);

	if(validate == 0)
		std::cerr << "The thread number: " << _idThread << " was started and running successfully" << std::endl;
	else
		std::cerr << "The thread number: " << _idThread << " was not started and not running successfully" << std::endl;

}

void platform::Thread::stopThread(){

	int validate = pthread_detach(_thread);

	if(validate == 0)
		std::cerr << "The thread number: " << _idThread << " was stopped successfully" << std::endl;
	else
		std::cerr << "The thread number: " << _idThread << " was not stopped successfully" << std::endl;

}

int platform::Thread::getID(){
	return _idThread;
}

pthread_t platform::Thread::getThread(){

	return _thread;
}

