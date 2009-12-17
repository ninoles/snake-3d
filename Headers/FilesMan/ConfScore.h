/*
 * ConfScore.h
 *
 *  Created on: 14/12/2009
 *      Author: Henrique Jonas
 */

#ifndef CONFSCORE_H_
#define CONFSCORE_H_

#include <irrlicht.h>
#include <irrXML.h>
#include <stdlib.h>

#include "../Player/GroupPlayers.h"
#include "../Platform/GUIManagement.h"

namespace file{

	class ConfScore{

		private:

			irr::IrrlichtDevice *_device;
			irr::io::IrrXMLReader *_xmlArchive;
			irr::io::IXMLWriter *_xmlArchiveWr;

		public:

			ConfScore(irr::IrrlichtDevice *__device);

			//Main Methods
			void setArchiveRead(char* __filename);
			void setArchiveWrite(const irr::c8* __filename);
			void closeXML();
			bool isXMLRead();


			Players::Player readPlayer();
			void writePlayer(Players::Player __player);

	};
}

#endif /* CONFSCORE_H_ */
