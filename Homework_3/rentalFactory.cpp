#include "rentalFactory.h"

Rental* rentalFactory::rentTools(Store* store,int nightMin,int nightMax,int toolMin,int toolMax, int curDate){
    //max number of tools to be rented
    int maxGen
    //ask store if there are enough tools
    int NumTools = store.NumberOfTools();
    //early exit if no tools to rent, this should never be hit
    if(NumTools == 0){
        return NULL;
    }
    if(toolMax <= NumTools){
        maxGen = toolMax;
    }else{
        maxGen = NumTools;
    }
    
    //guess random number of tools
    int ToolsRented = rand() % maxGen //this is totally wrong
    
    //build vector for rental object
    std::vector<Tool*> rentedtools;
    //Actually rent the tools
    for(int i = 0; i < ToolsRented;i++){
        rentedtools.push_back(store.BorrowTool());
    }
    //decide how long should be rented for
    int numDays = rand() % nightMax //also totally wrong
    
    return new Rental(rentedTools,numDays);
}
