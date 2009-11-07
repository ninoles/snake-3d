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

#include "../GenericList/ArrayList.h"

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

	};
}

#endif /* GUIMANAGEMENT_H_ */
