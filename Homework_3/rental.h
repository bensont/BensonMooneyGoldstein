#pragma once
#include <vector>
#include "tool.h"

class Rental{
public:
    Rental(std::vector<Tool*> intools,int date);
    int getDueDate();
private:
    int dueDate;
    std::vector<Tool*> rentedTools;
};
