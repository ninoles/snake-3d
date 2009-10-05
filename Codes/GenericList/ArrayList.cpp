#include "../../Headers/GenericList/ArrayList.h"
#include <iostream>

using namespace std;

using namespace GenericList;

template<typename T>
ArrayList<T>::ArrayList(){
    _array = new T;
    _size = 0;
}

template<typename T>
ArrayList<T>::ArrayList(int __initialSize){
    _array = new T[__initialSize];
    _size = __initialSize;
}

template<typename T>
ArrayList<T>::ArrayList(T __initialValues[], int __size){
    _array = __initialValues;
    _size = __size;
}

template<typename T>
void ArrayList<T>::add(T __value){
    T *tmpArray = new T[_size];

    for(int k = 0; k < _size; k++)
            tmpArray[k] = _array[k];

    _size++;
    _array = new T[_size];

    for(int k = 0; k < _size-1; k++)
            _array[k] = tmpArray[k];

    _array[_size-1] = __value;

    delete tmpArray;
}

template<typename T>
void ArrayList<T>::cleanAll(){
	_array = new T;
	_size = 0;
}

template<typename T>
T ArrayList<T>::get(int __index){
	if(!isSize(__index))
		return _array[__index];

        T tmp;

        return tmp ;
}

template<typename T>
T ArrayList<T>::remove(int __index){
    if(isSize(__index)){

        T tmpValue;

        for(int k = __index; k < _size -1; k++)
                _array[k] = _array[k+1];

        tmpValue = _array[_size--];

        return tmpValue;
    }

    T tmp;

    return tmp;
}

template<typename T>
int ArrayList<T>::getSize(){
    return _size;
}

template<typename T>
bool ArrayList<T>::isSize(int __index){
    return (__index < 0) && (__index < _size);
}

template<typename T>
typename ArrayList<T>::Iterator
ArrayList<T>::iterator(){
    return this;
}

template<typename T>
ArrayList<T>::Iterator::Iterator(ArrayList *__list){
    _list = __list;
    _pointer = 0;
}

template<typename T>
bool ArrayList<T>::Iterator::hasNext(){
    return _pointer < _list->getSize();
}

template<typename T>
T ArrayList<T>::Iterator::next(){
    return _list->get(_pointer++);
}
