#include "tool.h"
#include "store.h"
#include "customers.h"
#include <iostream>

int main(){
	
	//start by building a store
	Store store;
	//now we give the store a bunch of tools
	for(int i = 0;i<5;i++){
		Tool testTool(i,"test");
		store.ReturnTool(&testTool);
	}
	
	//create a bunch of customers
	std::vector<Customer> customers;
	//create a customer factory

	//have the factory fill the customer vector
	

	store.PrintStore();

	return 0;
}

