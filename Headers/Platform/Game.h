/*
 * Game.h
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#ifndef GAME_H_
#define GAME_H_

#include <irrlicht.h>

#include "FrameManagement.h"
#include "Gameplay.h"
#include "ThreadMatch.h"

#include "../Base/FrameCameraFPS.h"

namespace platform{

	class Game{

		private:

			static Game *_gameSing;

			FrameManagement *_frameMan;

			platform::Gameplay *_gamePlay;
			platform::ThreadMatch *_threadMatch;

			Game(){
			}

		public:

			static Game* getInstance();

			void initDisplay();

			void run();

	};

}

#endif /* GAME_H_ */
