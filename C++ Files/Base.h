#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string.h>
#include "Room.h"
#include "Item.h"
#include "Adventurer.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "rapidxml.hpp"
using namespace std;
using namespace rapidxml;


Item firstItemInit(xml_node<>*);
Room firstRoomInit(xml_node<>*);
Room* findRoom(Room*, char*, int);
void wireRoom(Room*, Room*, char*, char*, int);
Item* findItem(Item*, char*, int);
void wireItem(Item*, Item**, char*, int);

#endif
