#pragma once
#include "logger.h"
#include <vector>
#include "rental.h"
#include "tool.h"

struct RentalInfo{
    std::string CustomerName;
    std::vector<std::string> RentedTools;
    int NumberOfDays;
    int TotalPrice;
};

class RentalList{
public:
    //desctructor
    ~RentalList();
    void addRentalLog(std::string custName, Rental* rent);
    void displayLog();
private:
    std::vector<RentalInfo*> allRentals_;
};
