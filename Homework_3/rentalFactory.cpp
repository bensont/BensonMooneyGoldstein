#include "rentalFactory.h"
#include <iostream>

Rental* rentalFactory::rentTools(Store* store,int nightMin,int nightMax,int toolMin,int toolMax, int curDate){
    //max number of tools to be rented
    int maxGen;
    //ask store if there are enough tools
    int NumTools = store->NumberOfTools();
    //early exit if no tools to rent, this should never be hit
    if(NumTools == 0){
        return NULL;
    }
    if(toolMax <= NumTools){
        maxGen = toolMax;
    }else{
        maxGen = NumTools;
    }
    std::cout << "on day " <<std::to_string(curDate) << ", " <<std::to_string(maxGen) << " ";
    //guess random number of tools
    int ToolsRented;
    if(maxGen-toolMin > 0){
        ToolsRented = (rand() % (maxGen - toolMin +1)); //find the difference
    }else {
        ToolsRented = 0;
    }
    ToolsRented += toolMin;
    std::cout << std::to_string(toolMin) << " " << std::to_string(ToolsRented) << std::endl;
    if(ToolsRented > NumTools){
        //std::cout << std::to_string(ToolsRented) << std::endl;
        return NULL;
    }
    //std::cout << std::to_string(ToolsRented) << std::endl;
    
    //build vector for rental object
    std::vector<Tool*> rentedtools;
    //Actually rent the tools
    for(int i = 0; i < ToolsRented;i++){
        rentedtools.push_back(store->BorrowTool());
    }
    //decide how long should be rented for, copied logic from higher up
    
    int numDays;
    if(nightMax - nightMin > 0){
       numDays = rand() % (nightMax - nightMin+1);
    }else{
        numDays = 0;
    }
    numDays += nightMin;
    return new Rental(rentedtools,numDays+curDate);
}

void rentalFactory::returnTools(Store* store, Rental* rent){
    //break open the rental object
    std::vector<Tool*> returnTools = rent->getTools();
    std::cout << "here"<<std::to_string(returnTools.size()) <<std::endl;
    for(int i = 0; i< returnTools.size() ;i++){
        store->ReturnTool(returnTools.at(i));
    }
}
