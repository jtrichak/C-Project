#ifndef BORDERNODE_H
#define BORDERNODE_H
#include "Base.h"
#include "Room.h"

class BorderNode {
public:
	BorderNode();
	virtual ~BorderNode();
	BorderNode* genBorder();
	BorderNode* West;
	BorderNode* East;
	BorderNode* North;
	BorderNode* South;
	Room Current;

};

#endif
