#include "store.h"
#include <iostream>

Store::Store(){
    totalRevenue_ = 0;
}

void Store::displayRevenue(){
    std::cout << std::to_string(totalRevenue_) << " dollars "<< std::endl;
}

void Store::ReturnTool(Tool* t){
    //make sure it isn't null
    if(t != NULL){
        tools.push_back(t);
    }
}

void Store::CleanUp(){
	tools.clear();
}

int Store::NumberOfTools(){
    return tools.size();
}

Tool* Store::BorrowTool(){
    int inx = 0;
    Tool* curtool;
    
    //find a random tool somehow
    //add price to total revenue
    //return the random tool
    
    curtool = tools.at(inx);
    tools.erase(tools.begin()+inx);
    //add price
    totalRevenue_ += curtool->GetPrice();
    return curtool;
}

void Store::PrintStore(){
	for(std::vector<Tool*>::iterator i=tools.begin(); i!=tools.end(); ++i){
		(*i)->PrintTool();
	}
}/*
	for(std::vector<Tool*>::iterator i=tools.begin(); t=tools.end(); ++i){
		std::cout << i->PrintTool() << std::endl;
	}

	for(auto i : tools){
		std::cout << i->PrintTool << std::endl;
	}

	*/
