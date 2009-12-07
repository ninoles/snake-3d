#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

namespace GenericList{
	
	template<typename T>
	class ArrayList{
		
		private:
			T* _array;
			int _size;
			
			bool isSize(int __index);
			
		public:
			
			ArrayList();
			ArrayList(int __initialSize);
			ArrayList(T __initialValues[], int __size);
			
			void add(T __value);
			void cleanAll();
			
			T get(int __index);
			T remove(int __index);
			
			int getSize();
			
			class Iterator;
			friend class Iterator;
			
			Iterator iterator();
			
			class Iterator{

				private:

						ArrayList<T> *_list;
						int _pointer;

				public:
						Iterator(ArrayList *_list);
						T next();
						bool hasNext();

			};
	}; 

};

#endif /*ARRAYLIST_H_*/
