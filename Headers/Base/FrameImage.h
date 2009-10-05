/* 
 * File:   FrameImage.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 13:55
 */

#ifndef _FRAMEIMAGE_H
#define	_FRAMEIMAGE_H

#include <irrlicht.h>

namespace base{

    class FrameImage{

        private:

            irr::gui::IGUIImage *_image;

        public:

            FrameImage(irr::gui::IGUIImage *__image);
            
            void setImage(irr::gui::IGUIImage *__image);
            irr::gui::IGUIImage* getImageFrame();

    };
    
};



#endif	/* _FRAMEIMAGE_H */

