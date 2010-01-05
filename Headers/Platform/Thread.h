/*
 * Thread.h
 *
 *  Created on: 04/01/2010
 *      Author: Henrique Jonas
 */

#ifndef THREAD_H_
#define THREAD_H_

#ifdef WIN32

    #include <windows.h>
    #define sleepms(x) Sleep(x)

#elif defined(__linux__) || defined(MAC_OS)

    #include <unistd.h>
    #define sleepms(x) usleep(x * 1000)

#else

    #warning "Could not find an implementation for sleep for current OS. Game won't sleep"

    #define sleepms(x)

#endif

#include <pthread.h>
#include <iostream>
#include <time.h>

#include "Snake.h"

void* runSnake(void* __snake);
void* checkCollisionMap(void* __gamePlay);
void* checkCollisionNode(void* __gamePlay);
void* checkCollisionPoint(void* __gamePlay);

namespace platform{

	enum typeThread{

		THREAD_COLLISION_MAP,
		THREAD_COLLISION_POINT,
		THREAD_COLLISION_NODE,
		THREAD_MOVIMENT_NODE

	};

	class Thread{

		private:

			pthread_t _thread;
			int _idThread;

		public:

			Thread();

			void createThread(platform::Snake *__arg);
			void stopThread();
			int getID();

			pthread_t getThread();

	};
}

#endif /* THREAD_H_ */
