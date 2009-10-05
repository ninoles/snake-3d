/* 
 * File:   FrameButton.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 14:56
 */

#ifndef _FRAMEBUTTON_H
#define	_FRAMEBUTTON_H

#include <irrlicht.h>

namespace base{

    class FrameButton{

        private:

            irr::gui::IGUIButton *_button;

        public:

            FrameButton(irr::gui::IGUIButton *__button);
            void setFrameButton(irr::gui::IGUIButton *__button);
            irr::gui::IGUIButton* getFrameButton();

    };
}



#endif	/* _FRAMEBUTTON_H */

