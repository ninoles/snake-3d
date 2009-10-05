/* 
 * File:   FrameText.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 14:59
 */

#ifndef _FRAMETEXT_H
#define	_FRAMETEXT_H

#include <irrlicht.h>

namespace base{

    class FrameText{

        private:

            irr::gui::IGUIStaticText *_text;

        public:

            FrameText(irr::gui::IGUIStaticText *__text);

            void setText(irr::gui::IGUIStaticText *__text);
            irr::gui::IGUIStaticText* getText();
            
    };
};



#endif	/* _FRAMETEXT_H */

