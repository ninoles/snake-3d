/*
 * Game.h
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#ifndef GAME_H_
#define GAME_H_

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

#include <irrlicht.h>

#include "FrameManagement.h"
#include "Gameplay.h"

namespace platform{

	class Game{

		private:

			static Game *_gameSing;

			FrameManagement *_frameMan;

			platform::Gameplay *_gamePlay;

			Game(){
			}

		public:

			static Game* getInstance();

			void initDisplay();
			void generatMap();

			void run();

	};

}

#endif /* GAME_H_ */
