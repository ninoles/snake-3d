/*
 * Gameplay.h
 *
 *  Created on: 19/11/2009
 *      Author: henrique
 */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include <Newton.h>
#include <irrlicht.h>

namespace plataform{

	class Gameplay{

		private:

			NewtonWorld *_newtonW;
			irr::scene::ISceneManager *_sceneManagement;

		public:

			Gameplay();
			Gameplay(irr::scene::ISceneManager *__sceneManagement);

	};

}


#endif /* GAMEPLAY_H_ */
