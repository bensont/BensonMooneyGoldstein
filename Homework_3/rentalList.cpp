#include "rentalList.h"

void RentalList::displayLog(){
    Logger::print("Displaying Full Rental Log",message);
    RentalInfo* current;
    //Logger::print(std::to_string(allRentals_.size()),debug);
    for(int i = 0; i<allRentals_.size();i++){
        current = allRentals_.at(i);
        //copy out the struct
        for(int j = 0; j < current->RentedTools.size();j++){
            Logger::print(current->RentedTools.at(j),message);
        }
        Logger::print(current->CustomerName +" rented for " + std::to_string(current->NumberOfDays)+ " days with a total price of "+std::to_string(current->TotalPrice));
    }
}

void RentalList::addRentalLog(std::string custName, Rental* rent){
    RentalInfo* rentalRow = new RentalInfo;
    rentalRow->CustomerName = custName;
    rentalRow->NumberOfDays = rent->getNumberOfDaysRented();;
    rentalRow->TotalPrice = rent->getTotalPrice();
    for(int i = 0;i<rent->numTools();i++){
        rentalRow->RentedTools.push_back(rent->at(i)->GetCategory());
    }
    allRentals_.push_back(rentalRow);
}

RentalList::~RentalList(){
    //need to clear the vector of structs
    for(int i = 0; i<allRentals_.size();i++){
        allRentals_.at(i)->RentedTools.clear();
    }
}
