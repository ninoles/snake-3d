/*
 * File:   KeyBoardEvents.h
 * Author: Henrique Jonas
 * Version: 0.1 BETA
 * Created on 28 de Setembro de 2009, 18:07
 */

#ifndef KEYBOARDEVENTS_H_
#define KEYBOARDEVENTS_H_

#include <irrlicht.h>

namespace Events{
	
	class KeyBoardEvents{
		
		private:
			
			bool _keysDown[irr::KEY_KEY_CODES_COUNT];

		public:

                    KeyBoardEvents();
                    void inputKey(irr::EKEY_CODE __keyCode);
                    void deleteKey(irr::EKEY_CODE __keyCode);
                    bool isKeyDown(irr::EKEY_CODE __keyCode);

        };
};

#endif /*KEYBOARDEVENTS_H_*/
