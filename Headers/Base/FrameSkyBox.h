/* 
 * File:   FrameSkyBox.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 15:01
 */

#ifndef _FRAMESKYBOX_H
#define	_FRAMESKYBOX_H

#include <irrlicht.h>

namespace base{

    class FrameSkyBox{

        private:

            irr::scene::ISceneNode *_skyBox;

        public:

            FrameSkyBox(irr::scene::ISceneNode *__skyBox);

            void setSkyBox(irr::scene::ISceneNode *__skyBox);
            irr::scene::ISceneNode* getSkyBox();

    };
};



#endif	/* _FRAMESKYBOX_H */

