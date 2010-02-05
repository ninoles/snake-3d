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
#include "../Events/NodeMoviment.h"
#include "../Events/WrapperEvent.h"

void* snakeForward(void *__snake);
void* turnSnake(void *__snake);

namespace platform{

	enum typeThread{

		THREAD_MOVIMENT_FORWARD,
		THREAD_MOVIMENT_TURN

	};

	class ThreadSnake{

		private:

			pthread_t _threadRun;
			pthread_t _threadTurn;
			int _idThread;

		public:

			ThreadSnake();

			void createThread(platform::Snake *__arg);
			void pauseThread();
			void stopThread();
			int getID();

	};
}

#endif /* THREAD_H_ */
