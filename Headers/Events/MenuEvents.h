/*
 * File:   MenuEvents.h
 * Author: Henrique Jonas
 * Version: 0.1 BETA
 * Created on 27 de Setembro de 2009, 16:07
 */

#ifndef MENUEVENTS_H_
#define MENUEVENTS_H_

#include "../Context/SAppContext.h"

namespace Events{
	
	enum GameMenu{
		GUI_ID_PAUSE = 100,
		GUI_ID_LEAVE_GAME
	};
	
	enum MatchMenu{
		GUI_ID_BEST_PLAYERS = 110,
		GUI_ID_MATCHES
	};
	
	enum HelpMenu{
		GUI_ID_INSTRUCTIONS = 120,
		GUI_ID_ABOUT
	};
	
	enum ArchiveMenu{
		GUI_ID_NEW_GAME = 130,
		GUI_ID_LOAD_GAME,
		GUI_ID_PREFERENCES_GAME,
		GUI_ID_QUIT
	};
	
	enum PointMenu{
		GUI_ID_POINT_PLAYERS = 140,
		GUI_ID_WIN_PLAYERS
	};
	
	class MenuEvents{
		
		private:
			
			irr::IrrlichtDevice *_device;
			
		public:
			
			MenuEvents(irr::IrrlichtDevice *__device);

			void handler(int __idEvent);
	};
};

#endif /*MENUEVENTS_H_*/
