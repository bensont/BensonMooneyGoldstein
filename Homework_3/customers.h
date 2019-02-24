#pragma once
#include <vector>
#include "rental.h"

class Customer{
public:
	Customer();
	void purchaseTools();
private:
	std::vector<Rental> rentals;
};