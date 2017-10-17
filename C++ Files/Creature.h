#ifndef CREATURE_H_
#define CREATURE_H_

#include "Base.h"

class Creature(){
public:
	char* Name;
	char* Status;
	char* Description;

	//vulnerability
	//attack method
	//trigger

	Creature();
	virtual ~Creature();
}
