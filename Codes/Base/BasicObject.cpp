/*
 * BasicObject.cpp
 *
 *  Created on: 10/12/2009
 *      Author: Henrique Jonas
 */

#include "../../Headers/Base/BasicObject.h"

base::BasicObject::BasicObject(void* __object, int __id){

	if(BasicObject::validateID(__id))
		return;

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
	delete _object;
	_id = -1;
}
