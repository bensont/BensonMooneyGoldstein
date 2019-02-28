#pragma once
#include "tool.h" 
#include <vector>
#include "logger.h"

class Store{
public:
	Store();
	void ReturnTool(Tool *t);
	Tool* BorrowTool();
    void PrintStore();
    void CleanUp();
    int NumberOfTools();
    void displayRevenue(int day);
private:
    int totalRevenue_;
	std::vector<Tool*> tools;
};
