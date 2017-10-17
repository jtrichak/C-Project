#include "Base.h"
#include "Container.h"

Container::Container(){
	Name = (char*) "";
	Status = (char*) "";
	Description = (char*) "";
}

Container::~Container(){}

Container firstContainerInIt(xml_node<>* child){
	xml_node<>* child2 = child->first_node();
	Container curContainer = Container();
	while(child2 != 0){
		if(strcmp(child2 -> name(), (char*) "name") == 0) {
			curContainer.Name = child2->value();
		}
		if(strcmp(child2 -> name(), (char*) "description") == 0) {
			curContainer.Description = child2->value();
		}
		if(strcmp(child2 -> name(), (char*) "status") == 0) {
			curContainer.Status = child2->value();
		}
		child2 = child2->next_sibling();
	}
	return curContainer;
}

void wireContainer(Container* ContArray, Container** pointer, char* name, int maxContainer){
	*pointer = findContainer(ContArray, name, maxContainer);
	return;
}

Container* findContainer(Container* ContArray, char* name, int maxContainer){
	for(int i = 0; i < maxContainer, i++){
		if(strcmp(ContArray[i].Name, name) ==0){
			return (&(ContArray[i]));
		}
	}
	return NULL;
}
