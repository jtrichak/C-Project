#ifndef ROOM_H
#define ROOM_H
#include "Base.h"

class Room {
public:
	std::string Name, Status, Type, Description;
	//Container* container;
	//Item* item;
	//Creature* creature;
	//Trigger* trigger;
	Room();
	virtual ~Room();
	Room(std::string, std::string, std::string, std::string);

};

#endif
