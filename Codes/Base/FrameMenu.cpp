#include "../../Headers/Base/FrameMenu.h"

using namespace base;

FrameMenu::FrameMenu(){
    
}

FrameMenu::FrameMenu(irr::gui::IGUIContextMenu* __mainMenu){
    _mainMenu = __mainMenu;
}

void FrameMenu::setMainMenu(irr::gui::IGUIContextMenu* __mainMenu){
    _mainMenu = __mainMenu;
}

irr::gui::IGUIContextMenu* FrameMenu::getMainMenu(){
    return _mainMenu;
}

irr::gui::IGUIContextMenu* FrameMenu::addSubMenu(int __elementIndex){
	return _mainMenu->getSubMenu(__elementIndex);
}

void FrameMenu::addItemMainMenu(const wchar_t* __text, irr::s32 __idItem, bool __enabled, bool __hasSubMenu, bool __checked){
    _mainMenu->addItem(__text, __idItem, __enabled, __hasSubMenu);
}
