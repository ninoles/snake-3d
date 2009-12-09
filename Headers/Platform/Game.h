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
#include "GUIManagement.h"

#include "../Events/ButtonEvents.h"
#include "../FilesMan/FileManagement.h"

#include "../Physis/Gameplay.h"
#include "../Physis/MeshCollision.h"

using namespace file;
using namespace physis;

namespace plataform{

	class Game{

		private:

			static Game *_gameSing;

			FrameManagement *_frameMan;
			FileManagement *_fileMan;

			Gameplay *_gameManagement;

			base::FrameSceneNode* tmp;
			base::FrameSceneNode* tmp2;

			bool valida;

			Game(){
				_gameManagement = new Gameplay();
				valida = false;
			}

			void swapGUI(int __options);

		public:

			static Game* getInstance();

			void initDisplay();
			void generatMap();

			void run();

	};

}

#endif /* GAME_H_ */
