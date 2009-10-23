#include <irrlicht.h>

#include "../Headers/Base/Frame.h"
#include "../Headers/Plataform/FrameManagement.h"

#include <iostream>

using namespace plataform;
using namespace base;

int main() {

	FrameManagement *manage = new FrameManagement(800, 600, 32, false, false);

	manage->changeFrame(FRAME_ID_MAIN_MENU, false);

	while(manage->getBaseFrame()->frameRun())
		manage->getBaseFrame()->drawFrame();



}
