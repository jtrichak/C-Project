#include "Base.h"

Adventurer::Adventurer() { }
Adventurer::~Adventurer() { }

void Adventurer::move(Adventurer* adventurer, BorderNode* newLoc) {
	if(newLoc == NULL) {
		std::cout << "No room to enter" << std::endl;
	} else {
		adventurer -> Loc = newLoc;
	} 
	return;
}

void Adventurer::openExit(Adventurer* adventurer, int* exitVal) {
	if(adventurer -> Loc -> Current.Type == "Exit") {
		std::cout << "Congrats, you won!" << std::endl;
		*exitVal = 1;
	} else {
		std::cout << "This room is not the exit" << std::endl;
	}
	return;
}

