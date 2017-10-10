#include "Base.h"

Map::Map() { }
Map::~Map() { }

void genBorderNode(BorderNode* newNode, BorderNode* prev, std::string direction) {
	if(direction == "north") {
		newNode -> South = prev;
		prev -> North = newNode;
		newNode -> North = NULL;
		newNode -> East = NULL;
		newNode -> West = NULL;
	}
	else if (direction == "south") {
		newNode -> North = prev;
		prev -> South = newNode;
		newNode -> South = NULL;
		newNode -> West = NULL;
		newNode -> East = NULL;
	}
	else if (direction == "west") {
		newNode -> East = prev;
		prev -> West = newNode;
		newNode -> West = NULL;
		newNode -> North = NULL;
		newNode -> South = NULL;
	}
	else if (direction == "east") {
		newNode -> West = prev;
		prev -> East = newNode;
		newNode -> East = NULL;
		newNode -> North = NULL;
		newNode -> South = NULL;
	}
	else if (direction == "start") {
		newNode -> East = NULL;
		newNode -> North = NULL;
		newNode -> South = NULL;
		newNode -> West = NULL;	
	}
	else {
		ccout << "Error in genBorderNode" << endl;
	}
	return;
}
