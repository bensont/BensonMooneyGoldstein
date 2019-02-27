#pragma once
#include "rental.h"
#include "store.h"

class rentalFactory{
public:
    static Rental* rentTools(Store* store,int nightMin,int nightMax,int toolMin,int toolMax, int curDate);
    static void returnTools(Store* store, Rental* rent);
};
