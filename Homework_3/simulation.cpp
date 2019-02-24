#include "tool.h"
#include "store.h"
#include "customers.h"
#include "timecounter.h"
#include <iostream>

void BuildStore(Store* t,int max,std::string cat){
	for(int i = 0;i<4;i++){
		Tool* testTool = Tool::Create(max,cat+std::to_string(i+1));
		t->ReturnTool(testTool);
	}
	

}

int main(){
	//Create main time
    TimeCounter time(35);
    
	//start by building a store
	Store store;
    
	//now we give the store a bunch of tools
	BuildStore(&store,5,"painting");
	BuildStore(&store,7,"concrete");
	BuildStore(&store,6,"plumbing");
	BuildStore(&store,8,"woodwork");
	BuildStore(&store,4,"yardwork");
	
	//create a bunch of customers
	std::vector<Customer> customers;
	//create a customer factory

	//have the factory fill the customer vector
	
    //testing the store
	store.PrintStore();
    //testing the customers
    
    //day night cycle
    while(!time.IsDone()){
        if(time.IsDay()){
            //tool rental
            time.AdvanceDay();
        }
        else{
            //tool return
            time.AdvanceDay();
        }
    }

	//clean up step
	store.CleanUp();

	return 0;
}
