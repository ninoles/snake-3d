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

		public:

			static int global_index;

			BasicObject(void* __object, int __id);

			void* getObject();
			int getId();

			static void insertID(int __id){
				_ids[global_index++] = __id;
			}

			static void startCount(){
				global_index = 0;
			}

			static bool validateID(int __id){
				for(int index = 0; index < global_index; index++){
					if(__id == _ids[index])
						return false;
				}

				return true;
			}

			void dropObject();

	};

}

#endif /* BASICOBJECT_H_ */
