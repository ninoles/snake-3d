/* 
 * File:   ButtonEvents.h
 * Author: Henrique Jonas
 * Version: 0.1 BETA
 * Created on 29 de Setembro de 2009, 21:32
 */

#ifndef _BUTTONEVENTS_H
#define	_BUTTONEVENTS_H

#include "../Context/SAppContext.h"

#include "../../Headers/Plataform/GUIManagement.h"
#include "../../Headers/FilesMan/FileManagement.h"

namespace Events{

	enum MainMenuOptions{
		GUI_ID_CREATE_GAME_BUTTON = 500,
		GUI_ID_LOAD_GAME_BUTTON,
		GUI_ID_SCORE_BUTTON,
		GUI_ID_PREF_BUTTON,
		GUI_ID_HELP_GAME,
		GUI_ID_QUIT_GAME,
		GUI_ID_MAIN_MENU_GAME
	};

	enum fileOpenDialog{
		GUI_ID_FILE_OPEN = -1
	};

	enum recordFiles{
		GUI_ID_SAVE_PREF = 804,
		GUI_ID_SAVE_TYPE_GAME = 605,
		GUI_ID_SAVE_CURRENT_GAME
	};

	enum gameOptions{
			GAME_NOTHING_OPTION = -1,
			GAME_LOAD_ARCHIVE_GAME,
			GAME_LOAD_ARCHIVE_HELP,
			GAME_LOAD_ARCHIVE_INFO_SCORE,
			GAME_LOAD_ARCHIVE_PREF,
			GAME_SAVE_ARCHIVE_GAME,
			GAME_SAVE_ARCHIVE_PREF,
			GAME_SAVE_CURRENT_GAME,
			GAME_START_MATCH
	};

	enum playerScoreOptions{
			GUI_ID_LOAD_SCORE_PLAYERS = 900,
			GUI_ID_LOAD_WINS_PLAYERS,
			GUI_ID_LOAD_MATCH_PLAYERS
	};

    class ButtonEvents{

        private:

            irr::IrrlichtDevice *_device;

            file::FileManagement *_fileMan;
            gameOptions _options;

        public:

            ButtonEvents();
            ButtonEvents(irr::IrrlichtDevice *__device);
            void handler(int __idEvent);
            
            int getGameOption();
            void setGameOption(gameOptions __options);

    };
};

#endif	/* _BUTTONEVENTS_H */

