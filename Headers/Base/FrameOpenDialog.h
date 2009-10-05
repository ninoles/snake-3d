/* 
 * File:   FrameOpenDialog.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 19:40
 */

#ifndef _FRAMEOPENDIALOG_H
#define	_FRAMEOPENDIALOG_H

#include <irrlicht.h>

namespace base{

    class FrameOpenDialog{

        private:

            irr::gui::IGUIFileOpenDialog *_openDialog;

        public:

            FrameOpenDialog(irr::gui::IGUIFileOpenDialog *__openDialog);

            void setOpenDialog(irr::gui::IGUIFileOpenDialog *__openDialog);
            irr::gui::IGUIFileOpenDialog* getOpenDialog();

    };
};



#endif	/* _FRAMEOPENDIALOG_H */

