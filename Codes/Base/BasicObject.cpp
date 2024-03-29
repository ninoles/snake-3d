/*
 * BasicObject.cpp
 *
 *  Created on: 10/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Base/BasicObject.h"

base::BasicObject::BasicObject(void* __object, int __id){
	_object = __object;
	_id = __id;
}

base::BasicObject::BasicObject(){

}

void base::BasicObject::init(void* __object, int __id){
	_object = __object;
	_id = __id;
}

void* base::BasicObject::getObject(){
	return _object;
}

int base::BasicObject::getId(){
	return _id;
}

void base::BasicObject::dropObject(){
	_object = 0;
	_id = -1;
}
