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

#include "../FilesMan/FileManagement.h"

using namespace file;

namespace plataform{

	enum Options{
		GAME_NOTHING_OPTION = -1,
		GAME_LOAD_ARCHIVE_GAME,
		GAME_LOAD_ARCHIVE_HELP,
		GAME_LOAD_ARCHIVE_INFO_SCORE,
		GAME_SAVE_ARCHIVE_GAME,
		GAME_SAVE_ARCHIVE_PREF
	};

	class Game{

		private:

			static Game *_gameSing;

			FrameManagement *_frameMan;
			Options _gameCurrentOption;

			Game(){ }

		public:

			static Game* getInstance();

			void initDisplay();
			void setCurrentOption(Options __gameCurrent);

			void run();
	};

}

#endif /* GAME_H_ */
