#include "tool.h"
#include "store.h"
#include "customers.h"
#include "timecounter.h"
#include "customerFactory.h"
#include "rentalFactory.h"
#include <iostream>
#include <queue>
#include <time.h>
#include "rentalList.h"

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

//The store (pointer), customer list (pointer for ease), and current date
void NightCycle(Store* t, std::vector<Customer*>* c,RentalList* rlist,int curDate){
    std::vector<Rental*> returnedTools;
    for(int i = 0; i< c->size();i++){
        returnedTools = c->at(i)->returnTools(rlist,curDate);
        //std::cout << "hit customer "<< std::to_string(i+1) << std::endl;
        //make sure it isn't null
        
        if(returnedTools.size() != 0){
            for(int x = 0; x <returnedTools.size();x++){
                rentalFactory::returnTools(t,returnedTools.at(x));
            }
        }
        
        
    }
    
}

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
	
    //Create a rentallist
    RentalList rentalList;
    
    //If logger is in debug mode also print this
    if(Logger::isDebug()){
        store.PrintStore();
        for(int i = 0; i<customers.size();i++){
            customers.at(i)->display();
        }
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
            NightCycle(&store,&customers,&rentalList,time.get_day());
            //since every customer needs to check every day, no queue
            time.AdvanceDay(); //move to day of following morning
        }
    }

    
    Logger::print("Completed Rentals",message);
    rentalList.displayLog();
    
    Logger::print("Outstanding Rentals",message);
    for(int i = 0; i<customers.size();i++){
        //std::cout << "?"<< std::endl;
        customers.at(i)->display();
    }
    
    //display money earned
    store.displayRevenue(time.get_day());
    //Current number of store
    Logger::print("Final Store inventory of "+std::to_string(store.NumberOfTools())+" items",message);
    store.PrintStore();
    //time.get_day();
	//clean up step
    
    //Need to make sure things are cleaned up
	store.CleanUp();
    //clean each customer up
    customers.clear();
    //rental list is self cleaning

	return 0;
}
