#pragma once
#include <vector>
#include "tool.h"

class Rental{
public:
    Rental(std::vector<Tool*> intools,int date,int numdays);
    int getDueDate(); //get the due date
    void display();
    bool isEmpty();
    int numTools();
    int getTotalPrice();
    std::vector<Tool*> getTools();
    Tool* at(int k);
    int getNumberOfDaysRented();
private:
    int dueDate;
    int numberOfDaysRented_;
    std::vector<Tool*> rentedTools;
};
