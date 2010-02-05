/*
 * MatchArchive.h
 *
 *  Created on: 05/02/2010
 *      Author: Henrique Jonas
 */

#ifndef MATCHARCHIVE_H_
#define MATCHARCHIVE_H_

namespace file{

	class LoadMatch{

		private:

			irr::IrrlichtDevice *_device;
			irr::io::IrrXMLReader *_xmlReader;
			irr::io::IXMLWriter *_xmlWriter;

		public:

			LoadMatch();
			LoadMatch(irr::IrrlichtDevice *__device);

	};

}


#endif /* MATCHARCHIVE_H_ */
