#include "rental.h"

Rental::Rental(std::vector<Tool*> intools,int date,int numdays){
    rentedTools = intools;
    dueDate = date;
    numberOfDaysRented_ = numdays;
}

int Rental::getNumberOfDaysRented(){
    return numberOfDaysRented_;
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

int Rental::getTotalPrice(){
    int price = 0;
    for(int i = 0;i<rentedTools.size();i++){
        price += rentedTools.at(i)->GetPrice();
    }
    return price;
}

Tool* Rental::at(int k){
    return rentedTools.at(k);
}

std::vector<Tool*> Rental::getTools(){
    //This is also where we should log the record
    
    std::vector<Tool*> ret = rentedTools;
    //clear the vector
    rentedTools.clear();
    return ret;
}
