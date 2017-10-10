#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string.h>
#include "Adventurer.h"
#include "Room.h"
#include "Inventory.h"
#include "BorderNode.h"
#include "Map.h"
#include <vector>
#include <stdio.h>
#include <fstream>
#include "rapidxml.hpp"
using namespace std;
using namespace rapidxml;
void genBorderNode(BorderNode*);
void genRoom(Room*);

#endif
