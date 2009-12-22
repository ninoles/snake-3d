/*
 * Game.h
 *
 *  Created on: 31/10/2009
 *      Author: Henrique Jonas
 */

#ifndef GAME_H_
#define GAME_H_

#include <irrlicht.h>

#include "FrameManagement.h"
#include "../Physis/Gameplay.h"

#include "../Base/FrameAnimatedNode.h"
#include "../Base/FrameCameraFPS.h"
#include "../Base/FrameTerrainSceneNode.h"

namespace platform{

	class Game{

		private:

			static Game *_gameSing;

			FrameManagement *_frameMan;

			physis::Gameplay *_gamePlay;

			base::FrameAnimatedNode *_node1;
			base::FrameAnimatedNode *_node2;

			Game(){
			}

		public:

			static Game* getInstance();

			void initDisplay();
			void generatMap();

			void run();

	};

}

#endif /* GAME_H_ */
