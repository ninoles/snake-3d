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

void FrameMenu::addSubMenu(FrameMenu *__subMenu, int __elementIndex){
    irr::gui::IGUIContextMenu *tmp;

    tmp = __subMenu->getMainMenu();
    tmp = _mainMenu->getSubMenu(__elementIndex);
    
    __subMenu->setMainMenu(tmp);

    delete tmp;
}

void FrameMenu::addItemMainMenu(const wchar_t* __text, irr::s32 __idItem, bool __enabled, bool __hasSubMenu, bool __checked){
    _mainMenu->addItem(__text, __idItem, __enabled, __hasSubMenu, __checked);
}