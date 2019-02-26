#include "tool.h"
#include "store.h"
#include "customers.h"
#include "timecounter.h"
#include "customerFactory.h"
#include <iostream>
#include <queue>

void BuildStore(Store* t,int max,std::string cat){
	for(int i = 0;i<4;i++){
		Tool* testTool = Tool::Create(max,cat+std::to_string(i+1));
		t->ReturnTool(testTool);
	}
	

}

/*
void DayCycle(Store* t,std::vector<Customer> c,int curDate){
    //popque
    //Customer = popdfsadc
    if(Customer.canRent()){
        Customer.purchaseTools(t,curDate);
    }
}

void NightCycle(Store* t, std::vector<Customer> c,int curDate){
    for(Customer cust: c){
        std::vector<Rental*> = cust.returnTools(curDate);
        //process the return
    }
    
}
 */

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
	std::vector<Customer*> customers;
    //vector to hold customers to process
    std::queue<Customer*> custqueue;
    
	//create the first 3 customers
    
    customers.push_back(CustomerFactory::createCasual("cust1"));
    customers.push_back(CustomerFactory::createBusiness("cust2"));
    customers.push_back(CustomerFactory::createRegular("cust3"));
    
    //fill the rest randomly
    for(int i = 3;i<10;i++){
        customers.push_back(CustomerFactory::createRandom("cust"+std::to_string(i+1)));
    }
	//have the factory fill the customer vector
	
    //testing the store
	store.PrintStore();
    //testing the customers
    for(int i = 0; i<customers.size();i++){
        //std::cout << "?"<< std::endl;
        customers.at(i)->display();
    }
    
    //day night cycle
    /*
    while(!time.IsDone()){
        if(time.IsDay()){
            //If list is empty build list
            //for each person in list as them to rent
            time.AdvanceDay();
        }
        else{
            NightCycle(store,customers,time.get_day());
            time.AdvanceDay();
        }
    }

	//clean up step
    */
	store.CleanUp();
    //clean each customer up
    customers.clear();

	return 0;
}
