#include "store.h"
#include <iostream>

Store::Store(){

}

void Store::ReturnTool(Tool* t){
	tools.push_back(t);
}

void Store::CleanUp(){
	tools.clear();
}

void Store::PrintStore(){
	for(std::vector<Tool*>::iterator i=tools.begin(); i!=tools.end(); ++i){
		(*i)->PrintTool();
		std::cout << std::endl;
	}
}/*
	for(std::vector<Tool*>::iterator i=tools.begin(); t=tools.end(); ++i){
		std::cout << i->PrintTool() << std::endl;
	}

	for(auto i : tools){
		std::cout << i->PrintTool << std::endl;
	}

	*/