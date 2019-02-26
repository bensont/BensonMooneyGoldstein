#include "rental.h"

Rental::Rental(std::vector<Tool*> intools,int date){
    rentedTools = intools;
    dueDate = date;
}

int Rental::getDueDate(){
    return dueDate;
}

void Rental::display(){
    if(!isEmpty()){
        for(int i = 0;i<rentedTools.size();i++){
            rentedTools.at(i)->PrintTool();
        }
    }
}

bool Rental::isEmpty(){
    if(rentedTools.size() == 0){
        return true;
    }
    return false;
    
}

int Rental::numTools(){
    return rentedTools.size();
}
