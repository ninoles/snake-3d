/* 
 * File:   ButtonEvents.h
 * Author: Henrique Jonas
 * Version: 0.1 BETA
 * Created on 29 de Setembro de 2009, 21:32
 */

#ifndef _BUTTONEVENTS_H
#define	_BUTTONEVENTS_H

#include "../Context/SAppContext.h"
#include "../Plataform/GUIManagement.h"

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

    class ButtonEvents{

        private:

            irr::IrrlichtDevice *_device;

        public:

            ButtonEvents();
            ButtonEvents(irr::IrrlichtDevice *__device);
            void handler(int __idEvent);
            
    };
};


#endif	/* _BUTTONEVENTS_H */

