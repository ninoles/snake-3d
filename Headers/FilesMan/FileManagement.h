/* 
 * File:   FileManagement.h
 * Author: henrique
 *
 * Created on 30 de Setembro de 2009, 19:39
 */

#ifndef _FILEMANAGEMENT_H
#define	_FILEMANAGEMENT_H

#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "../Player/Player.h"
#include "../GenericList/ArrayList.h"

namespace file{

    class FileManagement{

		private:

			std::ofstream _out;
			std::ifstream _in;

			std::string _nameArchive;

		public:

			static const int MAX_CHAR = 80;

			FileManagement(std::string __nameArchive, string __extension);
			FileManagement() { }

			void openFileWrite(bool __modelCreateFile);
			void openFileRead();

			void saveElement(Players::Player __player);
			void saveElement(std::string __value);
			void saveConfigurationVideo(int __width, int __heigth, int __bitsPerPixel,
					bool __fullScreen, bool __stencilBuffer, bool __antiAliasing, bool __joyStick);

			void closeWrite();
			void closeRead();

			std::string getElement();
			GenericList::ArrayList<Players::Player> getPlayers();
			std::string* getConfigurations();


			std::string toString(char *__string);

    };
};



#endif	/* _FILEMANAGEMENT_H */

