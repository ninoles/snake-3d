/*
 * GUIManagement.h
 *
 *  Created on: 29/10/2009
 *      Author: henrique
 */

#ifndef GUIMANAGEMENT_H_
#define GUIMANAGEMENT_H_

#include <irrlicht.h>
#include <string>
#include <cstring>
#include <iostream>

#include "../GenericList/ArrayList.h"

using namespace std;

namespace plataform{

	class GUIManagement{

		private:

		public:

			const static int MAX_CHAR = 80;

			static std::string getTextElement(irr::s32 __primaryId, irr::gui::IGUIElement *__rootGUIElement){
				return toString(__rootGUIElement->getElementFromId(__primaryId, true)->getText());
			}

			static void setTextElement(irr::s32 __primaryId, wchar_t *__text, irr::gui::IGUIElement *__rootGUIElement){
				__rootGUIElement->getElementFromId(__primaryId, false)->setText(__text);
			}

			static irr::gui::IGUIElement* getElement(irr::s32 __primaryId, irr::gui::IGUIElement *__rootGUIElement){
				return __rootGUIElement->getElementFromId(__primaryId, false);
			}

			static std::string toString(const wchar_t *__array){

				std::string tmp = "";

				char *array = new char[MAX_CHAR];
				int count;

				for(count = 0; (__array[count] - 48) != -48; count++)
					array[count] = __array[count];

				for(int k = 0; k < count; k++)
					tmp += array[k];

				delete [] array;

				return tmp;

			}

			static std::string toString(bool __value){
				if(__value)
					return "true";
				return "false";
			}

			static bool toBoolean(string __phrase){
				if(__phrase == "1" || __phrase == "True" || __phrase == "true")
					return true;
				return false;
			}

			static std::string* getTokens(string __delimiter, string __phrase){

				char* phrase = new char[__phrase.size()+1];
				char *tmp;

				strcpy(phrase, __phrase.c_str());

				tmp = strtok(phrase, __delimiter.c_str());

				std::string word[MAX_CHAR];

				for(int k = 0; tmp != NULL; k++){
					word[k] = tmp;
					tmp = strtok(NULL, __delimiter.c_str());
				}

				delete [] phrase;
				delete [] tmp;

				return word;
			}

	};
}

#endif /* GUIMANAGEMENT_H_ */
