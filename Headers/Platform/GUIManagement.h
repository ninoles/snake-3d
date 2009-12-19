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

class GUIManagement{

	public:

		const static int MAX_CHAR = 80;

		static const wchar_t* getTextElement(irr::s32 __primaryId, irr::gui::IGUIElement *__rootGUIElement){
			return __rootGUIElement->getElementFromId(__primaryId, true)->getText();
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

		static wchar_t* toWChar(bool __value){
			if(__value)
				return L"1";
			return L"0";
		}

		static wchar_t* getTokens(const wchar_t* __phrase, wchar_t* __delimiter, int __token){

			int count_1 = 0;
			int count_2 = 0;
			int index = 0;

			while(__phrase[count_1] != __delimiter[0])
				count_1++;

			while((__delimiter[index] - 48) != -48)
				index++;

			count_2 += count_1 + index;

			while((__phrase[count_2] - 48) != -48)
				count_2++;

			wchar_t *phraseRet;

			if(__token == 1){
				phraseRet = new wchar_t[count_1];

				for(int k = 0; k < count_1; k++)
					phraseRet[k] = __phrase[k];

				return phraseRet;

			} else if(__token == 2){
				phraseRet = new wchar_t[count_2 - count_1];

				for(int k = count_1+index, i = 0; k < count_2; k++, i++)
					phraseRet[i] = __phrase[k];

				return phraseRet;
			}

			return 0;
		}

		static wchar_t* toWChar(char *__phrase){

			int count = 0;

			while(__phrase[count] != '\0')
				count++;

			wchar_t *phrase = new wchar_t[count];

			for(int k = 0; k < count ; k++)
				phrase[k] = __phrase[k];

			return phrase;
		}
};

#endif /* GUIMANAGEMENT_H_ */
