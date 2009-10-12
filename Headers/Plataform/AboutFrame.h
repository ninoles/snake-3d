/*
 * AboutFrame.h
 *
 *  Created on: 12/10/2009
 *      Author: Henrique Jonas
 */

#ifndef ABOUTFRAME_H_
#define ABOUTFRAME_H_

#include <irrlicht.h>

#include "../../Headers/Base/Frame.h"
#include "../../Headers/Base/FrameText.h"
#include "../../Headers/Base/FrameImage.h"
#include "../../Headers/Base/FrameButton.h"

using namespace base;

namespace plataform{

	class AboutFrame{

		private:

			Frame *_frame;

			FrameButton *_closeWindow;

			FrameImage *_backGround;

			void initComponents();

		public:

			AboutFrame();

			void displayFrame(bool __visible);

			Frame* getFrame();
	};
};


#endif /* ABOUTFRAME_H_ */
