/*
 * InitalFrame.h
 *
 *  Created on: 12/10/2009
 *      Author: Henrique Jonas
 */

#ifndef INITALFRAME_H_
#define INITALFRAME_H_

#include "../Base/Frame.h"
#include "../Base/FrameMenu.h"

using namespace base;

namespace plataform{

	class InitialFrame{
		private:

			Frame *_frame;

			FrameMenu *_menu;

			void initComponents();
			void createMenu();

		public:

			InitialFrame();

			void displayFrame(bool __visible);

			Frame* getFrame();
	};

};



#endif /* INITALFRAME_H_ */
