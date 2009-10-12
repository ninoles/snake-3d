#include <irrlicht.h>

#include "../Headers/Plataform/InitalFrame.h"
#include "../Headers/Base/Frame.h"

using namespace plataform;
using namespace base;

int main() {

	InitialFrame *frame = new InitialFrame();

	frame->displayFrame(true);

	while(frame->getFrame()->frameRun())
			if(frame->getFrame()->windowActive())
				frame->displayFrame(true);

		frame->displayFrame(false);

	return 0;

}
