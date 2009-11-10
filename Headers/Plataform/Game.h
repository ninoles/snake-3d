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
#include "GUIManagement.h"

#include "../Events/ButtonEvents.h"
#include "../Events/WrapperEvent.h"
#include "../FilesMan/FileManagement.h"

using namespace file;

namespace plataform{

	class Game{

		private:

			static Game *_gameSing;

			FrameManagement *_frameMan;
			FileManagement *_fileMan;

			Game(){ }

		public:

			static Game* getInstance();

			void initDisplay();

			void run();
	};

}

#endif /* GAME_H_ */
