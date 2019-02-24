#include "rental.h"

Rental::Rental(std::vector<Tool*> intools,int date){
    rentedTools = intools;
    dueDate = date;
}

int Rental::getDueDate(){
    return dueDate;
}
