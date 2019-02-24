#pragma once
#include "tool.h" 
#include <vector>

class Store{
public:
	Store();
	void ReturnTool(Tool *t);
	Tool BorrowTool();
    void PrintStore();
    void CleanUp();
private:
	std::vector<Tool*> tools;
};
