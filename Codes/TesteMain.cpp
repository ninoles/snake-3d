#include <irrlicht.h>

#include "../Headers/Base/Frame.h"
#include "../Headers/Base/FrameButton.h"

using namespace base;

int main() {

	Frame *frame = new Frame(600, 400, 16, true, false);

	FrameButton button(frame->addButton(irr::core::rect<irr::s32>(10,240,110,240 + 32), 0, 0, L"New Window", L"Open new windows."));
	FrameImage image(frame->addImage("/home/henrique/Imagens/grass2kl3.jpg", irr::core::position2d<irr::s32>(300,300), false, 0, 0, L"ASD"));

	while(frame->frameRun())
		if(frame->windowActive())
			frame->drawFrame();

	frame->closeFrame();

	return 0;

}
