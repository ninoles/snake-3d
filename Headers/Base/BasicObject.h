/*
 * BasicObject.h
 *
 *  Created on: 10/12/2009
 *      Author: Henrique Jonas
 */

#ifndef BASICOBJECT_H_
#define BASICOBJECT_H_

#define MAX_ID 10000

namespace base{

	class BasicObject{

		private:

			void *_object;
			int _id;

			static int _ids[MAX_ID];
			static int index;

		protected:

			void init(void* __object, int __id);

		public:

			BasicObject(void* __object, int __id);
			BasicObject();

			void* getObject();
			int getId();

			static void insertID(int __id){
				_ids[index++] = __id;
			}

			static int generateID(){
				int number = _ids[index-1];
				return number++;
			}

			static void startCount(){
				index = 0;
			}

			void dropObject();

	};

}

#endif /* BASICOBJECT_H_ */
