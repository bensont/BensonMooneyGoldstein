#pragma once
#include <vector>
#include <string>
#include "rental.h"

class Customer{
public:
	Customer();
	void purchaseTools();
private:
	std::string name_;
	std::vector<Rental> rentals_;
};

class Casual: public Customer {
	// rent 1 or 2 tools for 1 or 2 nights
	void purchaseTools() {

	}
};

class Business: public Customer {
	// rent 3 tools for 7 nights
	void purchaseTools() {

	}
};

class Regular: public Customer {
	// rent 1- 3 tools for 3-5 nights
	void purchaseTools() {

	}
};
