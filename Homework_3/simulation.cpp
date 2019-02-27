#include "tool.h"
#include "store.h"
#include "customers.h"
#include "timecounter.h"
#include "customerFactory.h"
#include <iostream>
#include <queue>
#include <time.h>

void BuildStore(Store* t,int prc,std::string cat){
	for(int i = 0;i<4;i++){
		Tool* testTool = Tool::Create(prc,cat+std::to_string(i+1));
		t->ReturnTool(testTool);
	}
	

}

void DayCycle(Store* t,std::queue<Customer*>* c,int curDate){
    Customer* cust;
    while(!c->empty()){
        cust = c->front();
        c->pop();
        if(cust->canRent()){
            cust->purchaseTools(t,curDate);
        }
    }
}
/*
void NightCycle(Store* t, std::vector<Customer> c,int curDate){
    for(Customer cust: c){
        std::vector<Rental*> = cust.returnTools(curDate);
        //process the return
    }
    
}
 */

int main(){
    //seed random
    srand(time(NULL));
    
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
	
    //testing the store
	store.PrintStore();
    //testing the customers
    for(int i = 0; i<customers.size();i++){
        //std::cout << "?"<< std::endl;
        customers.at(i)->display();
    }
    
    //day night cycle
    
    while(!time.IsDone()){
        if(time.IsDay()){
            int r;
            for(int i = 0; i<customers.size();i++){
                r = rand() % 3; //customers have a 1/3 chance of going to store
                if(r == 0){
                    custqueue.push(customers.at(i));
                }
            }
            DayCycle(&store,&custqueue,time.get_day()); //actually deal with customers at store
            time.AdvanceDay(); //move to night of same day
        }
        else{
            //NightCycle(store,customers,time.get_day());
            time.AdvanceDay(); //move to day of following morning
        }
    }

    //print out the customers stuff
    for(int i = 0; i<customers.size();i++){
        //std::cout << "?"<< std::endl;
        customers.at(i)->display();
    }
    
    //display money earned
    std::cout << "Over " << std::to_string(time.get_day()) << " days earned ";
    store.displayRevenue();
    //Current number of store
    //std::cout<<store.NumberOfTools()<<std::endl;
    store.PrintStore();
    //time.get_day();
	//clean up step
    //std::cout<<time.get_day()<<std::endl;
    
    //Need to make sure things are cleaned up
	store.CleanUp();
    //clean each customer up
    customers.clear();

	return 0;
}
