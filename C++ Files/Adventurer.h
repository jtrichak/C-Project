#ifndef ADVENTURER_H
#define ADVENTURER_H
#include "BorderNode.h"

class Adventurer {
public:
	BorderNode* Loc;
	//Inventory Inv;

	Adventurer();
	virtual ~Adventurer();

	void move(Adventurer*, BorderNode*);
	//void inventory(Inventory);
	//void take(Inventory*, Room*);
	//void drop(Inventory*, Room*);
	//void open(Room*, Adventurer*); //Needs to check Adventurer for objects?
	//void read(Inventory);
	void openExit(Adventurer*, int*);    //Int can be a main flag, indicates game still active
	//void notInInventory(Item);      //Prints item is not present in inventory
	//void putItem(Inventory*, Room*, std::string); //Changes ownership from Item to Container name in Room 
	//void turnOn(Item*); 
	//void attack()
};

#endif
