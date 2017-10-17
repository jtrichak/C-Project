#include "Base.h"
#include "Creature.h"

Creature::Creature(){
	Name = (char*) "";
	Status = (char*) "";
	Description = (char*) "";
}

Creature::Creature(){}

Creature firstCreatureInIt(xml_node<>* child){
	xml_node<>* child2 = child->first_node();
	Creature curCreature = Creature();
	while(child2 != 0){
		if(strcmp(child2 -> name(), "name") == 0){
			curCreature.Name = child2->value();
		}
		if(strcmp(child2 -> name(), "Status") == 0){
			curCreature.Status = child2->value();
		}
		if(strcmp(child2 -> name(), "Description") == 0){
			curCreature.Description = child2->value();
		}
	}
	return curCreature;
}

void wireCreature(Creature* CreatureArray, Creature** pointer, char* name, int maxCreature){
	*pointer = findCreature(CreatureArray, name, maxCreature);
	return;
}

Creature* findCreature(Creature CreatureArray, char* name, int maxCreature){
	for(int i = 0; i < maxCreature; i++){
		if(strcmp(CreatureArray[i].Name, name) ==0){
			return(&(CreatureArray[i]));
		}
	}
	return NULL;
}
