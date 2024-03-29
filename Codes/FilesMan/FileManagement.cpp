/*
 * FileManagement.cpp
 *
 *  Created on: 24/10/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/FilesMan/FileManagement.h"

using namespace file;
using namespace std;
using namespace Players;
using namespace GenericList;

FileManagement::FileManagement(string __nameArchive, string __extension){
        _nameArchive = __nameArchive + __extension;

}

void FileManagement::openFileWrite(bool __modelCreateFile){
        if(__modelCreateFile)
                _out.open(_nameArchive.c_str(), ios::out | ios::app);
        else
                _out.open(_nameArchive.c_str(), ios::out);
}

void FileManagement::openFileRead(){
        _in.open(_nameArchive.c_str(), ios::in);
}

void FileManagement::saveElement(Player __player){
        _out << __player.getName();
        _out << endl;
        _out << __player.getNumberGames();
        _out << endl;
        _out << __player.getScore();
        _out << endl;
        _out << __player.getWins();
        _out << endl;
}

/*
 * Order of record informations of screen
 *
 * 1- Width
 * 2- Heigth
 * 3- Bits per pixel
 * 4- FullScreen
 * 5- Stencil Buffer
 *
 */
void FileManagement::saveConfigurationVideo(int __width, int __heigth, int __bitsPerPixel,
					bool __fullScreen, bool __stencilBuffer, bool __antiAliasing, bool __joyStick){

	_out << __width;
	_out << endl;
	_out << __heigth;
	_out << endl;
	_out << __bitsPerPixel;
	_out << endl;
	_out << __fullScreen;
	_out << endl;
	_out << __stencilBuffer;
	_out << endl;
	_out << __antiAliasing;
	_out << endl;
	_out << __joyStick;

	closeWrite();

}

void FileManagement::saveElement(string __value){
        _out << __value;
        _out << endl;
}

void FileManagement::closeWrite(){
        _out.close();
}

void FileManagement::closeRead(){
        _in.close();
}

string FileManagement::getElement(){
	if(!_in.eof()){

		char tmpLine[MAX_CHAR];
		_in.getline(tmpLine, MAX_CHAR);

		return toString(tmpLine);
	}

	return "/0";
}

ArrayList<Player> FileManagement::getPlayers(){
        ArrayList<Player> listPlayers;

        Player tmpPlayer;

        char tmpLine[MAX_CHAR];

        while(_in.eof()){
                _in.getline(tmpLine, MAX_CHAR);
                tmpPlayer.setName(toString(tmpLine));

                _in.getline(tmpLine, MAX_CHAR);
                tmpPlayer.setNumberGames(atoi(tmpLine));

                _in.getline(tmpLine, MAX_CHAR);
                tmpPlayer.setScore(atoi(tmpLine));

                _in.getline(tmpLine, MAX_CHAR);
                tmpPlayer.setWins(atoi(tmpLine));

                listPlayers.add(tmpPlayer);
        }

        closeRead();

        return listPlayers;
}

string* FileManagement::getConfigurations(){

	string tmp[5];

	char tmpLine[MAX_CHAR];

	for(int i = 0; _in.eof(); i++){
		_in.getline(tmpLine, MAX_CHAR);
		tmp[i] = toString(tmpLine);
	}

	return tmp;
}

string FileManagement::toString(char *__string){
        string tmp = "";

        for(int k = 0; k < MAX_CHAR && __string[k] != '\0'; k++)
                tmp += __string[k];

        return tmp;
}
