#pragma once
#include "rental.h"
#include "store.h"

static class rentalFactory{
public:
    Rental* rentTools(Store* store,int nightMin,int nightMax,int toolMin,int toolMax);
};
