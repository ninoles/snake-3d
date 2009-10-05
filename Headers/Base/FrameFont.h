/* 
 * File:   FrameFont.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 15:03
 */

#ifndef _FRAMEFONT_H
#define	_FRAMEFONT_H

#include <irrlicht.h>

namespace base{

    class FrameFont{

        private:

            irr::gui::IGUIFont *_font;

        public:

            FrameFont(irr::gui::IGUIFont *__font);

            void setFont(irr::gui::IGUIFont *__font);
            irr::gui::IGUIFont* getFont();
            
    };
};



#endif	/* _FRAMEFONT_H */

