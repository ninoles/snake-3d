/*
 * ConfScore.cpp
 *
 *  Created on: 14/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/FilesMan/ConfScore.h"

#include <iostream>

file::ConfScore::ConfScore(irr::IrrlichtDevice *__device){
	_device = __device;
}

void file::ConfScore::setArchiveRead(char *__filename){
	_xmlArchive = irr::io::createIrrXMLReader(__filename);
}

void file::ConfScore::setArchiveWrite(const irr::c8* __filename){
	_xmlArchiveWr = _device->getFileSystem()->createXMLWriter(__filename);

	_xmlArchiveWr->writeXMLHeader();
	_xmlArchiveWr->writeComment(L"Configurations of players");
	_xmlArchiveWr->writeElement(L"player");

}

bool file::ConfScore::isXMLRead(){
	return _xmlArchive && _xmlArchive->read();
}

Players::Player file::ConfScore::readPlayer(){
	Players::Player player;

	if(_xmlArchive == 0)
		return player;

	while((player.getName() == "" || player.getNumberGames() == -1 || player.getScore() == -1 || player.getWins() == -1) && isXMLRead()){
		switch(_xmlArchive->getNodeType()){

			case irr::io::EXN_ELEMENT:

				if(!strcmp("name", _xmlArchive->getNodeName()))
					player.setName(std::string(_xmlArchive->getAttributeValue("value")));
				else if(!strcmp("score", _xmlArchive->getNodeName()))
					player.setScore(_xmlArchive->getAttributeValueAsInt("value")+1);
				else if(!strcmp("wins", _xmlArchive->getNodeName()))
					player.setWins(_xmlArchive->getAttributeValueAsInt("value")+1);
				else if(!strcmp("matches", _xmlArchive->getNodeName()))
					player.setNumberGames(_xmlArchive->getAttributeValueAsInt("value")+1);
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

	return player;
}

void file::ConfScore::closeXML(){
	_xmlArchiveWr->writeClosingTag(L"player");
	_xmlArchiveWr->drop();
}

void file::ConfScore::writePlayer(Players::Player __player){

	if(_xmlArchiveWr == 0)
			return;

	char tmp[80];

	_xmlArchiveWr->writeElement(L"name", true, L"value", GUIManagement::toWChar((char*)__player.getName().c_str()));
	sprintf(tmp, "%d", (__player.getScore()+1));
	_xmlArchiveWr->writeElement(L"score", true, L"value", GUIManagement::toWChar(tmp));
	sprintf(tmp, "%d", (__player.getWins()+1));
	_xmlArchiveWr->writeElement(L"wins", true, L"value", GUIManagement::toWChar(tmp));
	sprintf(tmp, "%d", (__player.getNumberGames()+1));
	_xmlArchiveWr->writeElement(L"matches", true, L"value", GUIManagement::toWChar(tmp));
	_xmlArchiveWr->writeLineBreak();

}
