#include "tool.h"
#include <iostream>

Tool::Tool(){
	price = -1;
	category = "None";
}

Tool::Tool(int pc, std::string cat){
	price = pc;
	category = cat;
}

int Tool::GetPrice(){
	return price;
}

void Tool::SetPrice(int x){
	price = x;
}

void Tool::PrintTool(){
	std::cout << "Category: " << category << " Price: " << std::to_string(price);
}