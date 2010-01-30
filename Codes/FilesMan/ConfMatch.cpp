/*
 * ConfigMatchManagement.cpp
 *
 *  Created on: 13/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/FilesMan/ConfMatch.h"

file::ConfMatch::ConfMatch(irr::IrrlichtDevice *__device){
	_device = __device;
}

file::ConfMatch::ConfMatch(){

}

void file::ConfMatch::setArchiveRead(char* __filename){
	_xmlArchive = irr::io::createIrrXMLReader(__filename);
}

void file::ConfMatch::setArchiveWrite(const irr::c8* __filename){
	_xmlArchiveWr = _device->getFileSystem()->createXMLWriter(__filename);
}

void file::ConfMatch::readConfiguration(){

	if(_xmlArchive == 0)
			return;

	while(_xmlArchive && _xmlArchive->read()){

		switch(_xmlArchive->getNodeType()){

			case irr::io::EXN_ELEMENT:
				if(!strcmp("numberPlayers", _xmlArchive->getNodeName()))
					_numberPlayers = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("dificulty", _xmlArchive->getNodeName()))
					_dificulty = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("maxPoints", _xmlArchive->getNodeName()))
					_maxPoints = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("intelligence", _xmlArchive->getNodeName()))
					_intelligence = _xmlArchive->getAttributeValueAsInt("value");
				else if(!strcmp("bonusMap", _xmlArchive->getNodeName()))
					_mapsBonus = _xmlArchive->getAttributeValueAsInt("value");
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

void file::ConfMatch::writeConfigurations(const wchar_t* __numberPlayers, const wchar_t* __dificulty, const wchar_t* __maxPoints, const wchar_t* __intelligence,
		const wchar_t* __mapBonus){

	if(_xmlArchiveWr == 0)
			return;

	_xmlArchiveWr->writeXMLHeader();
	_xmlArchiveWr->writeComment(L"Configurations of current match");
	_xmlArchiveWr->writeElement(L"configurations");
	_xmlArchiveWr->writeElement(L"numberPlayers", true, L"value", __numberPlayers);
	_xmlArchiveWr->writeElement(L"dificulty", true, L"value", __dificulty);
	_xmlArchiveWr->writeElement(L"maxPoints", true, L"value", __maxPoints);
	_xmlArchiveWr->writeElement(L"intelligence", true, L"value", __intelligence);
	_xmlArchiveWr->writeElement(L"bonusMap", true, L"value", __mapBonus);
	_xmlArchiveWr->writeClosingTag(L"configurations");

	_xmlArchiveWr->drop();
}

int file::ConfMatch::getNumberOfPlayers(){
	return _numberPlayers;
}

int file::ConfMatch::getDificulty(){
	return _dificulty;
}

int file::ConfMatch::getMaxPoints(){
	return _maxPoints;
}

bool file::ConfMatch::isIntelligence(){
	return _intelligence;
}

bool file::ConfMatch::isMapBonus(){
	return _mapsBonus;
}

