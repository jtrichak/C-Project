#include "Base.h"

int main(int argc, char* argv[]) {


	int gameActive = 1;
	char* fileInput = new char[50];
	while(gameActive == 1) {
		scanf("%s", fileInput);
		ifstream myfile(fileInput);
		if(myfile.is_open()) {

			rapidxml::xml_document<> doc;
			vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));
			buffer.push_back('\0');
			doc.parse<0>(&buffer[0]);
			xml_node<>* node = doc.first_node();
			xml_node<>* child;
			xml_node<>* copyChild;
			xml_node<>* child2;
			xml_node<>* child3;
			xml_node<>* child4;


			int maxRoomCount = 0;		//Maximum amount of game rooms
			int maxItemCount = 0;		//Maximum amount of game items
			int maxCreatCount = 0;		//Maximum amount of game creatures
			int maxContCount = 0;		//Maximum amount of game containers
			int i = 0;
			int j = 0;

			while(node != 0) {
				child = node -> first_node();
				while(child != 0) {
					if(strcmp(child->name(), "room") == 0) {
						maxRoomCount++;
					}
					else if(strcmp(child->name(), "item") == 0) {
						maxItemCount++;
					}
					else if(strcmp(child->name(), "creature") == 0) {
						maxCreatCount++;
					}
					else if(strcmp(child->name(), "container") == 0) {
						maxContCount++;
					}
					child = child -> next_sibling();
				}
				node = node -> next_sibling();
			}

			Room* roomArray = new Room[maxRoomCount]; 							// Array of all possible rooms
			Item* itemArray = new Item[maxItemCount];							// Array of all possible items
			//Creature* creatArray = new Creature[maxCreatCount]				// Array of all possible creatures
			//Container* contArray = new Container[maxContCount]				// Array of all possible containers
			Item** inventory = new Item*[maxItemCount];							// Array of items on the adventurer

			Item*** roomInventories = new Item**[maxRoomCount];					// Array of size room, holds array of item pointers for each room
			for(i = 0; i < maxRoomCount; i++) {
				inventory[i] = NULL;
				roomInventories[i] = new Item*[maxItemCount];
				for(j = 0; j < maxItemCount; j++) {
					roomInventories[i][j] = NULL;								// Initializes all pointers in the item pointers in each room to NULL
				}
			}

			int* roomInventoryCount = new int[maxRoomCount];
			for(i = 0; i < maxRoomCount; i++) {
				roomInventoryCount[i] = 0;
			}

			/*
			   for(i = 0; i < maxRoomCount; i++) {
			   roomArray[i].roomItem = new Item*[maxItemCount];
			//roomArray[i].roomContainer = new Container*[maxContCount];		Cant use this section, I assumed you can declare ** in an object
			//roomArray[i].roomCreature = new Creature*[maxCreatCount];			and malloc later, but need size. Finding size through DOC instead
			//roomArray[i].roomTrigger = new Trigger*[maxTrigCount];
			}

			for(i = 0; i < maxRoomCount; i++) {
			for(j = 0; j < maxItemCount; j++) {
			roomArray[i].roomItem[j] = NULL;
			}
			}


			for(i = 0; i < maxRoomCount; i++) {
			for(j = 0; j < maxCreatCount; j++) {
			roomArray[i].roomCreature[j] = NULL;
			}
			}

			for(i = 0; i < maxRoomCount; i++) {
			for(j = 0; j < maxContCount; j++) {
			roomArray[i].roomContainer[j] = NULL;
			}
			}
			*/

			int inventoryCount = 0;			// Number of items in adventurer's inventory

			node = doc.first_node();
			int curRoom = 0;
			int curItem = 0;
			int curCreat = 0;
			int curCont = 0;

			while(node != 0) {
				child = node->first_node();
				while(child != 0) {
					if(strcmp(child->name(), (char*) "room") == 0) {
						roomArray[curRoom] = firstRoomInit(child);
						curRoom++;
					}
					else if(strcmp(child->name(), (char*) "item") == 0) {
						itemArray[curItem] = firstItemInit(child);
						curItem++;
					}
					else if(strcmp(child->name(), (char*) "creature") == 0) {
						//TODO - add first Creature initialization
					}
					else if(strcmp(child->name(), (char*) "container") == 0) {
						//TODO - add first Container initialization
					}
					child = child -> next_sibling();
				}
				node = node -> next_sibling();
			}

			node = doc.first_node();
			curRoom = 0;
			curItem = 0;
			curCreat = 0;
			curCont = 0;
			Room roomToWire = roomArray[curRoom];
			char* direction;
			char* name;

			while(node != 0) {
				child = node -> first_node();
				while(child != 0) {
					if(strcmp(child->name(), (char*) "room") == 0) {
						child2 = child -> first_node();
						while(child2 != 0) {
							if(strcmp(child2 -> name(), (char*) "border") == 0) {
								child3 = child2 -> first_node();
								while(child3 != 0) {
									if(strcmp(child3 -> name(), (char*) "name") == 0) {
										name = child3 -> value();
									}
									else if(strcmp(child3 -> name(), (char*) "direction") == 0) {
										direction = child3 -> value();
									}
									child3 = child3 -> next_sibling();
								}
								wireRoom(roomArray, &(roomArray[curRoom]), name, direction, maxRoomCount); // Points the borders of the current room to the proper room in roomArray
							}
							else if(strcmp(child2 -> name(), (char*) "item") == 0) {
								wireItem(itemArray, &(roomInventories[curRoom][roomInventoryCount[curRoom]]), child2 -> value(),  maxItemCount); // Points the proper room in the roomArray to the proper item in itemArray
								roomInventoryCount[curRoom]++;
								// NEED REWORK - individual room inventories???
							}
							child2 = child2 -> next_sibling();
						}
						curRoom++;
					}
					else if (strcmp(child->name(), (char*) "item") == 0) {
						// TODO - address any pointers in an item
					}
					else if (strcmp(child->name(), (char*) "creature") == 0) {
						// TODO - address any pointers in a creature
					}
					else if (strcmp(child->name(), (char*) "container") == 0) {
						// TODO - address any pointers in a container
					}
					child = child -> next_sibling();
				}
				node = node -> next_sibling();
			}
			Adventurer player = Adventurer();
			//player.Loc = gameMap.Start;
			player.Loc = findRoom(roomArray, (char*) "Entrance", maxRoomCount); 	// Finds room named Entrance in roomArray, points adventurer to that room
			std::string comp_input;
			char* first_word = new char[10];
			char* second_word = new char[20];
			char* third_word = new char[20];
			char* fourth_word = new char[30];
			char take[5] = "take";	
			i = 0;

			std::cout << player.Loc -> Description << std::endl;
			while (gameActive == 1) {
				std::getline(std::cin, comp_input);
				if(comp_input == "n") {
					player.move(&player, player.Loc -> Border[0]);
				}
				else if(comp_input == "s") {
					player.move(&player, player.Loc -> Border[2]);
				}
				else if(comp_input == "w") {
					player.move(&player, player.Loc -> Border[3]);
				}
				else if(comp_input == "e") {
					player.move(&player, player.Loc -> Border[1]);
				}
				else if(comp_input == "open exit") {
					player.openExit(&player, &gameActive);
				}
				else if(comp_input == "i") {
					player.inventory(inventory);
				}
				else if(strcmp(first_word, take) == 0) {
					std::cout << "LOL THIS ACTUALLY WORKED" << std::endl;
				}
				else {
					if(i == 1) {
						std::cout << "Input is incorrect" << std::endl;
					} else {
						i = 1;
					}
				}
			}


			if(roomArray != NULL) {
				delete [] roomArray;
			}
			if(itemArray != NULL) {
				delete [] itemArray;
			}
			/*if(creatArray != NULL) {
			  delete [] creatArray;
			  }
			  if(contArray != NULL) {
			  delete [] contArray;
			  }
			  */
		}
	}
	delete [] fileInput;
	return 0;
}
