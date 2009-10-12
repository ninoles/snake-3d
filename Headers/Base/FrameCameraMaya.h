/* 
 * File:   FrameCameraMaya.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 14:59
 */

#ifndef _FRAMECAMERAMAYA_H
#define	_FRAMECAMERAMAYA_H

#include <irrlicht.h>

namespace base{
    
    class FrameCameraMaya{

        private:

            irr::scene::ISceneNodeAnimatorCameraMaya *_cameraMaya;

        public:

            FrameCameraMaya(irr::scene::ISceneNodeAnimatorCameraMaya *__cameraMaya);

            void setCameraMaya(irr::scene::ISceneNodeAnimatorCameraMaya *__cameraMaya);
            irr::scene::ISceneNodeAnimatorCameraMaya* getCameraMaya();
    };
};



#endif	/* _FRAMECAMERAMAYA_H */
