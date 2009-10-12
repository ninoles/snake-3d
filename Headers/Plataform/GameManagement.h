/*
 * GameManagement.h
 *
 *  Created on: 12/10/2009
 *      Author: Henrique Jonas
 *
 */

#ifndef GAMEMANAGEMENT_H_
#define GAMEMANAGEMENT_H_

#include <irrlicht.h>

namespace plataform{

	class GameManagement{

		private:


		public:

			GameManagement();

			static irr::video::ITexture* loadTexture(const irr::c8 *__filename);
			static irr::gui::IGUIFont* loadFont(const irr::c8* __filename);

	};
};


#endif /* GAMEMANAGEMENT_H_ */
