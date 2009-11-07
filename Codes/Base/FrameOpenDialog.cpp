#include "../../Headers/Base/FrameOpenDialog.h"

using namespace base;

FrameOpenDialog::FrameOpenDialog(irr::gui::IGUIFileOpenDialog* __openDialog){
    _openDialog = __openDialog;
}

void FrameOpenDialog::setOpenDialog(irr::gui::IGUIFileOpenDialog* __openDialog){
    _openDialog = __openDialog;
}

irr::gui::IGUIFileOpenDialog* FrameOpenDialog::getOpenDialog(){
    return _openDialog;
}