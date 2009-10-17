#include <irrlicht.h>

#include "../Headers/Plataform/InitalFrame.h"
#include "../Headers/Plataform/AboutFrame.h"
#include "../Headers/Base/Frame.h"

using namespace plataform;
using namespace base;

int main() {

	AboutFrame *frame = new AboutFrame();

	while(frame->getFrame()->frameRun())
			if(frame->getFrame()->windowActive())
				frame->displayFrame(true);

		frame->displayFrame(false);

	return 0;

}
