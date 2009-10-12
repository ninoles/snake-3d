/* 
 * File:   WrapperEvent.h
 * Author: henrique
 *
 * Created on 29 de Setembro de 2009, 22:11
 */

#ifndef _WRAPPEREVENT_H
#define	_WRAPPEREVENT_H

#include <irrlicht.h>

#include "../Context/SAppContext.h"

#include "ButtonEvents.h"
#include "KeyBoardEvents.h"
#include "NodeMoviment.h"
#include "MenuEvents.h"

namespace Events{

    class WrapperEvents : public irr::IEventReceiver{

        private:

            irr::IrrlichtDevice *_device;

            Events::ButtonEvents *_eventButton;
            Events::MenuEvents *_eventMenu;
            Events::NodeMoviment *_eventNode;

        public:

            WrapperEvents(irr::IrrlichtDevice *__device);

            void setAllEvents();

            bool OnEvent(const irr::SEvent& event);
            
    };

};


#endif	/* _WRAPPEREVENT_H */
