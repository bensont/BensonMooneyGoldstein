#pragma once
#include <string>

class Tool{
public:
	Tool();
	Tool(int pc, std::string cat);
	void SetPrice(int x);

	int GetPrice();
	std::string GetCategory();
	void PrintTool();
private:
	int price;
	std::string category;
};