/* 
 * File:   ButtonEvents.h
 * Author: henrique
 * Version: 0.1 BETA
 * Created on 29 de Setembro de 2009, 21:32
 */

#ifndef _BUTTONEVENTS_H
#define	_BUTTONEVENTS_H

#include "../Context/SAppContext.h"

namespace Events{

    class ButtonEvents{

        enum ButtonOptions{
            GUI_ID_START_BUTTON = 160,
            GUI_ID_CREATE_GAME_BUTTON,
            GUI_ID_LOAD_GAME_BUTTON,
            GUI_ID_CONT_GAME
        };

        private:

            irr::IrrlichtDevice *_device;

        public:

            ButtonEvents();
            ButtonEvents(irr::IrrlichtDevice *__device);
            void handler(int __idEvent);
            
    };
};


#endif	/* _BUTTONEVENTS_H */

