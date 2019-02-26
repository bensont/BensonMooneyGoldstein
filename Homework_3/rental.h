#pragma once
#include <vector>
#include "tool.h"

class Rental{
public:
    Rental(std::vector<Tool*> intools,int date);
    int getDueDate(); //get the due date
    void display();
    bool isEmpty();
    int numTools();
private:
    int dueDate;
    std::vector<Tool*> rentedTools;
};
