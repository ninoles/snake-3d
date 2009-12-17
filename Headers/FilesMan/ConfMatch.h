/*
 * ConfMatch.h
 *
 *  Created on: 13/12/2009
 *      Author: Henrique Jonas
 */

#ifndef CONFMATCH_H_
#define CONFMATCH_H_

#include <irrXML.h>
#include <irrlicht.h>

namespace file{

	class ConfMatch{

		private:
				int _numberPlayers;
				int _dificulty;
				int _maxPoints;
				bool _intelligence;
				bool _mapsBonus;

				irr::IrrlichtDevice *_device;
				irr::io::IrrXMLReader *_xmlArchive;
				irr::io::IXMLWriter *_xmlArchiveWr;

			public:
				//Constructor
				ConfMatch(irr::IrrlichtDevice *__device);

				//Main Methods
				void setArchiveRead(char* __filename);
				void setArchiveWrite(const irr::c8* __filename);
				void readConfiguration();
				void writeConfigurations(const wchar_t* __numberPlayers, const wchar_t* __dificulty, const wchar_t* __maxPoints, const wchar_t* __intelligence,
						const wchar_t* __mapBonus);

				//Getters
				int getNumberOfPlayers();
				int getDificulty();
				int getMaxPoints();
				bool isIntelligence();
				bool isMapBonus();

	};
}

#endif /* CONFIGMATCHMANAGEMENT_H_ */
