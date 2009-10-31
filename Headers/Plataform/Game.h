/*
 * Game.h
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#include <irrlicht.h>

#include "FrameManagement.h"
#include "GUIManagement.h"

#include "../FilesMan/FileManagement.h"

#ifndef GAME_H_
#define GAME_H_

namespace plataform{

	enum options{
		GAME_LOAD_ARCHIVE_GAME = 0,
		GAME_LOAD_ARCHIVE_HELP,
		GAME_LOAD_ARCHIVE_INFO_SCORE,
		GAME_SAVE_ARCHIVE_GAME,
		GAME_SAVE_ARCHIVE_PREF
	};

	class Game{

		private:

			FrameManagement *_frameMan;

			static options _gameCurrentOption;

		public:

			Game();

			static void setCurrentOption(options __gameOp);

			void run();

	};

}


#endif /* GAME_H_ */
