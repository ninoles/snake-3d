/*
 * ConfFrame.cpp
 *
 *  Created on: 13/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/FilesMan/ConfFrame.h"

file::ConfFrame::ConfFrame(irr::IrrlichtDevice *__device){
	_device = __device;
}

file::ConfFrame::ConfFrame(){
}

void file::ConfFrame::setArchiveRead(char* __filename){
	_xmlArchive = irr::io::createIrrXMLReader(__filename);
}

void file::ConfFrame::setArchiveWrite(const irr::c8* __filename){
	_xmlArchiveWr = _device->getFileSystem()->createXMLWriter(__filename);
}

void file::ConfFrame::readConfigurations(){

	if(_xmlArchive == 0)
		return;

	while(_xmlArchive && _xmlArchive->read()){

		switch(_xmlArchive->getNodeType()){

			case irr::io::EXN_ELEMENT:
				if(!strcmp("width", _xmlArchive->getNodeName()))
					_width = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("heigth", _xmlArchive->getNodeName()))
					_heigth = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("bitsPerPixel", _xmlArchive->getNodeName()))
					_bitsPerPixel = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("fullScreen", _xmlArchive->getNodeName()))
					_fullscreen = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("stencilBuffer", _xmlArchive->getNodeName()))
					_stencilBuffer = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("anti-aliasing", _xmlArchive->getNodeName()))
					_antiAliasing = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("joystick", _xmlArchive->getNodeName()))
					_activateJoyStick = _xmlArchive->getAttributeValueAsInt("value");
				break;

			case irr::io::EXN_CDATA:
				break;

			case irr::io::EXN_COMMENT:
				break;

			case irr::io::EXN_ELEMENT_END:
				break;

			case irr::io::EXN_NONE:
				break;

			case irr::io::EXN_TEXT:
				break;

			case irr::io::EXN_UNKNOWN:
				break;

		}
	}
}

int file::ConfFrame::readWidth(){
	return _width;
}

int file::ConfFrame::readHeigth(){
	return _heigth;
}

int file::ConfFrame::readBitsPerPixel(){
	return _bitsPerPixel;
}

bool file::ConfFrame::readActivateJoy(){
	return _activateJoyStick;
}

bool file::ConfFrame::readAntiAliasing(){
	return _antiAliasing;
}

bool file::ConfFrame::readFullScreen(){
	return _fullscreen;
}

bool file::ConfFrame::readStencilBuffer(){
	return _stencilBuffer;
}

void file::ConfFrame::writeConfigurations(const wchar_t* _width, const wchar_t* _heigth, const wchar_t* _bitsPerPixel, const wchar_t* _activateJoyStick,
		 const wchar_t* _antiAliasing, const wchar_t* _fullscreen, const wchar_t* _stencilBuffer){

	if(_xmlArchiveWr == 0)
		return;

	_xmlArchiveWr->writeXMLHeader();
	_xmlArchiveWr->writeComment(L"Configurations of display frame");
	_xmlArchiveWr->writeElement(L"configurations");
	_xmlArchiveWr->writeElement(L"width", true, L"value", _width);
	_xmlArchiveWr->writeElement(L"heigth", true, L"value", _heigth);
	_xmlArchiveWr->writeElement(L"bitsPerPixel", true, L"value", _bitsPerPixel);
	_xmlArchiveWr->writeElement(L"fullScreen", true, L"value", _fullscreen);
	_xmlArchiveWr->writeElement(L"stencilBuffer", true, L"value", _stencilBuffer);
	_xmlArchiveWr->writeElement(L"anti-aliasing", true, L"value", _antiAliasing);
	_xmlArchiveWr->writeElement(L"joystick", true, L"value", _activateJoyStick);
	_xmlArchiveWr->writeClosingTag(L"configurations");

	_xmlArchiveWr->drop();
}

