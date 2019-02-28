#pragma once
#include "logger.h"

class Tool{
public:

	Tool();
	Tool(int pc, std::string cat);
	~Tool();

	//an inbuild factory
	static Tool* Create(int pc, std::string cat);

	void SetPrice(int x);

	int GetPrice();
	std::string GetCategory();
	void PrintTool();
private:
	int price;
	std::string category;
};
