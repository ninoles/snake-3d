/*
 * FrameManagement.h
 *
 *  Created on: 18/10/2009
 *      Author: Henrique Jonas
 */

#ifndef FRAMEMANAGEMENT_H_
#define FRAMEMANAGEMENT_H_

#include "../Base/Frame.h"
#include "../FilesMan/ConfFrame.h"

namespace platform{

	class FrameManagement{

		private:

			base::Frame *_frame;

		public:

			FrameManagement(int __width, int __heigth, int __bitsPerPixel, bool __fullScreen,
					bool __stencilBuffer, bool __activateJoystick, bool __antiAliasing);

			void switchScreens(int __newScreen);

			base::Frame* getBaseFrame();
	};
}

#endif /* FRAMEMANAGEMENT_H_ */
