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

Tool::~Tool(){
	//default destructor
	price = -1;
	//category = NULL;
}

Tool* Tool::Create(int pc, std::string cat){
	return new Tool(pc,cat);
}

int Tool::GetPrice(){
	return price;
}

void Tool::SetPrice(int x){
	price = x;
}

void Tool::PrintTool(){
    std::cout << "Category: " << category << " Price: " << std::to_string(price) << std::endl;
}
