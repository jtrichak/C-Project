#include "Base.h"
#include "rapidxml.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace rapidxml;
using namespace std;

int main(int argc, char* argv[]) {
	ifstream myfile("input.xml");
		rapidxml::xml_document<> doc;
		vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));
	    buffer.push_back('\0');
	    doc.parse<0>(&buffer[0]);
	    xml_node<> *node = doc.first_node();
	    xml_node<> *child = node->first_node();
	    xml_node<> *child2 = child->first_node();
	    xml_node<> *child3 = child2->first_node();
	    xml_node<> *child4 = child3->first_node();

	    Map gameMap;
	    BorderNode* current;
	    int firstRoom = 2;

	    while(node != 0) {
	    	child = node->first_node();
	    	while(child != 0) {
	    		if(strcmp(node->name(), "room") == 0) {
	    			Room curRoom;
	    			if(firstRoom == 2) {
	    				firstRoom = 1;
	    				gameMap.Start = new BorderNode();
	    				gameMap.Start -> Current = curRoom;
	    				genBorderNode(gameMap.Start, NULL, "start");
	    			}
	    			child2 = child->first_node();
	    			while(child2 != 0) {
	    				if(strcmp(child2 -> name(), "name") == 0) {
	    					curRoom.Name = child2->value();
	    				}
	    				else if(strcmp(child2 -> name(), "description") == 0) {
	    					curRoom.Description = child2->value();
	    				}
	    				else if(strcmp(child2 -> name(), "container") == 0) {

	    				}
	    				else if(strcmp(child2 -> name(), "border") == 0) {
	    					child3 = child2 -> first_node();
	    					while(child3 != 0) {
	    						if(strcmp(child3 -> name(), "direction") == 0) {
	    							Room NextRoom;
	    							BorderNode* NewRoomNode = new BorderNode();
	    							NextRoom.Name = child3 -> next_sibling() -> value();
	    							NewRoomNode->Current = NextRoom;
	    							genBorderNode(NewRoomNode, PrevRoomNode, child3 -> value());
	    							~NextRoom();
	    						}
	    					}
	    				}
	    				child2 = child2 -> next_sibling();
	    			}
				}
	    		child = child -> next_sibling();
	    	}
	    	node = node -> next_sibling();
	    }




	        child = node->first_node();

	        while (child != 0) {
	    	    cout<<"--------------"<<child->name()<<"--------------"<<endl;
	            child2 = child->first_node();
	            while (child2 != 0){
	                cout << child2->name() << "::" << child2->value() << endl;
	                child2 = child2->next_sibling();
	            }
	            cout<<"--------------/"<<child->name()<<"--------------"<<endl<<endl;;
	            child = child->next_sibling();
	        }

	        node = node->next_sibling();
	    }

	
	/*
	Adventurer player;
	Map map;
	BorderNode* current;
	BorderNode* current2;
	Room entrance;
	Room regRoom;
	Room exit;
	int gameActive = 0;

	entrance.Name = "Entrance";
	entrance.Type = "Regular";
	entrance.Status = "";
	entrance.Description = "Ben and Maria sitting in a tree";

	regRoom.Name = "Regular Room";
	regRoom.Type = "Regular";
	regRoom.Status = "";
	regRoom.Description = "T-A-L-K-I-N-G";

	exit.Name = "Exit Room";
	exit.Type = "Exit";
	exit.Status = "";
	exit.Description = "Finally he nut inside and all was well";

	map.Start = new BorderNode();
	current = map.Start;

	//player.Inv = NULL;
	player.Loc = map.Start;
	current -> West = new BorderNode();
	current -> East = NULL;
	current -> South = new BorderNode();
	current -> North = NULL;
	current -> Current = entrance;

	current = current -> West;
	current -> North = NULL;
	current -> East = map.Start;
	current -> South = new BorderNode();
	current -> West = NULL;
	current -> Current = regRoom;
	current -> Current.Description = "If you can travel south, Joe has nutted 20 times this month";

	current2 = current;
	current = current -> South;
	current -> North = current2;
	current -> West = NULL;
	current -> East = NULL;
	current -> South = NULL;
	current -> Current = regRoom;
	current -> Current.Description = "KAPPA OVERRATED, POGCHAMP OUTDATED, LONG HAVE WE WAITED, NOW WE JEBAITED";

	current = map.Start -> South;
	current2 = map.Start;
	current -> North = current2;
	current -> East = new BorderNode();
	current -> West = NULL;
	current -> South = new BorderNode();
	current2 = current;
	current -> Current.Description = "My Dad left me at a young age";

	current = current -> South;
	current -> North = current2;
	current -> West = NULL;
	current -> East = NULL;
	current -> South = NULL;
	current -> Current = regRoom;
	current -> Current.Description = "One final JEBAITED, you almost there young lad";

	current = current2 -> East;
	current -> West = current2;
	current -> North = NULL;
	current -> South = NULL;
	current -> East = NULL;
	current -> Current = exit;

	char* input;
	while (gameActive == 0) {
		std::cout << player.Loc -> Current.Description << std::endl;
		scanf("%s", input);
		if(input == "n") {
			player.move(&player, player.Loc -> North);
		}
		else if(input == "s") {
			player.move(&player, player.Loc -> South);
		}
		else if(input == "w") {
			player.move(&player, player.Loc -> West);
		}
		else if(input == "e") {
			player.move(&player, player.Loc -> East);
		}
		else if(input == "open exit") {
			player.openExit(&player, &gameActive);
		}
		else {
			std::cout << "Input is incorrect" << std::endl;
		}
	}
	*/
	return 0;
}
