/*
 * Map.h
 *
 *  Created on: 25/12/2009
 *      Author: Henrique Jonas
 */

#ifndef MAP_H_
#define MAP_H_

#include <irrlicht.h>
#include <Newton.h>
#include <time.h>

#include "../Base/FrameAnimatedNode.h"
#include "../Base/FrameSkyBox.h"

#define POSITION_X_MAP 0
#define POSITION_Y_MAP 0
#define POSITION_Z_MAP 0

#define SCALE_X_MAP 0
#define SCALE_Y_MAP 0
#define SCALE_Z_MAP 0

#define SKY_LEFT	"textures/sky_left.jpg"
#define SKY_RIGHT	"textures/sky_right.jpg"
#define SKY_BOTTOM	"textures/sky_bottom.jpg"
#define SKY_TOP		"textures/sky_top.jpg"
#define SKY_BACK	"textures/sky_back.jpg"
#define SKY_FRONT	"textures/sky_front.jpg"

#define MAP_ONE		"meshes/map_1_teste.3ds"
#define MAP_TWO		""
#define MAP_THREE	""
#define MAP_FOUR	""

namespace platform{

	class Map{

		private:

			base::FrameAnimatedNode *_mapOne;
			base::FrameAnimatedNode *_mapTwo;
			base::FrameAnimatedNode *_mapThree;
			base::FrameAnimatedNode *_mapFour;

			base::FrameSkyBox *_skyBox;

			irr::scene::ISceneManager *_sceneManager;
			irr::video::IVideoDriver *_videoDriver;
			NewtonWorld *_newtonW;

		public:

			Map(irr::scene::ISceneManager *__sceneManager, irr::video::IVideoDriver *__videoDriver, NewtonWorld *__newtonW);

			void initMaps();
			void loadSkyBox();

			void generateRandomMap();
			void flushScene();

	};
}

#endif /* MAP_H_ */