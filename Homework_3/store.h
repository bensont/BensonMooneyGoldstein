#pragma once
#include "tool.h" 
#include <vector>

class Store{
public:
	Store();
	void ReturnTool(Tool *t);
	Tool* BorrowTool();
    void PrintStore();
    void CleanUp();
    int NumberOfTools();
private:
    int totalRevenue_;
	std::vector<Tool*> tools;
};
