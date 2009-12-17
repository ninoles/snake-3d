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

namespace platform{

	class Game{

		private:

			static Game *_gameSing;

			FrameManagement *_frameMan;

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
