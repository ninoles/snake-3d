/* 
 * File:   FrameMenu.h
 * Author: henrique
 *
 * Created on 3 de Outubro de 2009, 15:35
 */

#ifndef _FRAMEMENU_H
#define	_FRAMEMENU_H

#include "../GenericList/ArrayList.h"

#include <IGUIContextMenu.h>
#include <string>

namespace base{

    class FrameMenu{

        private:

            irr::gui::IGUIContextMenu *_mainMenu;

        public:

            FrameMenu();
            FrameMenu(irr::gui::IGUIContextMenu *__mainMenu);

            void setMainMenu(irr::gui::IGUIContextMenu *__mainMenu);
            irr::gui::IGUIContextMenu* getMainMenu();

            void addItemMainMenu(const wchar_t *text, irr::s32 commandId, bool enabled, bool hasSubMenu, bool checked);

            irr::gui::IGUIContextMenu* addSubMenu(int __elementIndex);

    };

    
};


#endif	/* _FRAMEMENU_H */

