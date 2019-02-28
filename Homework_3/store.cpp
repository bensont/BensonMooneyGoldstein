#include "store.h"

Store::Store(){
    totalRevenue_ = 0;
}

void Store::displayRevenue(int day){
    Logger::print("Over " + std::to_string(day) + " days earned " + std::to_string(totalRevenue_)+ " dollars",message);
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
}
