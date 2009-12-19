/*
 * ConfFrame.h
 *
 *  Created on: 13/12/2009
 *      Author: Henrique Jonas
 */

#ifndef CONFFRAME_H_
#define CONFFRAME_H_

#include <irrlicht.h>
#include <irrXML.h>

namespace file{

	class ConfFrame{

		private:

			irr::IrrlichtDevice *_device;
			irr::io::IrrXMLReader *_xmlArchive;
			irr::io::IXMLWriter *_xmlArchiveWr;

			int _width, _heigth, _bitsPerPixel;
			bool _fullscreen, _stencilBuffer, _antiAliasing, _activateJoyStick;

		public:
			//Constructor
			ConfFrame(irr::IrrlichtDevice *__device);
            ConfFrame();

			//Main Methods
			void setArchiveRead(char* __filename);
			void setArchiveWrite(const irr::c8* __filename);
			void readConfigurations();
			void writeConfigurations(const wchar_t* _width, const wchar_t* _heigth, const wchar_t* _bitsPerPixel, const wchar_t* _activateJoyStick,
					 const wchar_t* _antiAliasing, const wchar_t* _fullscreen, const wchar_t* _stencilBuffer);

			int readWidth();
			int readHeigth();
			int readBitsPerPixel();
			bool readActivateJoy();
			bool readAntiAliasing();
			bool readFullScreen();
			bool readStencilBuffer();

	};
}

#endif /* CONFFRAME_H_ */
