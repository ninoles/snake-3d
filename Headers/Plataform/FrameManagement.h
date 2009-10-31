/*
 * FrameManagement.h
 *
 *  Created on: 18/10/2009
 *      Author: Henrique Jonas
 */

#ifndef FRAMEMANAGEMENT_H_
#define FRAMEMANAGEMENT_H_

#include "GUIManagement.h"
#include "../Base/Frame.h"

namespace plataform{

	class FrameManagement{

		private:

			base::Frame *_baseFrame;

		public:

			FrameManagement(int __width, int __heigth, int __bitsPerPixel,
					bool __fullScreen, bool __stencilBuffer);

			base::Frame* getBaseFrame();
	};
}

#endif /* FRAMEMANAGEMENT_H_ */
