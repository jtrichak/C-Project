#include "Base.h"

Adventurer::Adventurer() {
	Loc = NULL;
}
Adventurer::~Adventurer() { }

void Adventurer::inventory(Item** Inventory) {
	int i = 0;
	if(Inventory[i] == NULL) {
		std::cout << "Inventory: Empty" << std::endl;
	} else {
		std::cout << "Inventory: ";
		for(i = 0; Inventory[i] != NULL; i++) {
			std::cout << Inventory[i] -> Name;
			if(Inventory[i + 1] != NULL) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	return;
}
void Adventurer::move(Adventurer* adventurer, Room* newLoc) {
	if(newLoc == NULL) {
		std::cout << "Can't go that way" << std::endl;
	} else {
		adventurer -> Loc = newLoc;
		std::cout << adventurer -> Loc -> Description << std::endl;
	} 
	return;
}

void Adventurer::openExit(Adventurer* adventurer, int* exitVal) {
	if(strcmp(adventurer -> Loc->Type, "exit") == 0) {
		std::cout << "Congrats, you won!" << std::endl;
		*exitVal = 0;
	} else {
		std::cout << "This room is not the exit" << std::endl;
	}
	return;
}


