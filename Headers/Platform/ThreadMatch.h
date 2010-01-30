/*
 * ThreadMatch.h
 *
 *  Created on: 26/01/2010
 *      Author: Henrique Jonas
 */

#ifndef THREADMATCH_H_
#define THREADMATCH_H_

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

#include "Gameplay.h"

void* pointManagement(void *__game);
void* checkForCollision(void *__game);

namespace platform{

	class ThreadMatch{

		private:

			pthread_t _threadPoint;
			pthread_t _threadCollision;
			int _idThread;

		public:

			ThreadMatch();

			void createThread(platform::Gameplay *__arg);
			void pauseThread();
			void stopThread();
			int getID();

	};

}

#endif /* THREADMATCH_H_ */
