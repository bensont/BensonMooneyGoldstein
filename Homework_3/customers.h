#pragma once
#include <vector>
#include <string>
#include "rental.h"

class Customer{
public:
	Customer();
	void purchaseTools(Store* s, int cur_date);
	void returnTools(int date);
	bool canRent();
private:
	std::string name_;
	int n_min_; // rental min/max nights
	int n_max_;
	int t_min_; // tool min/max rented
	int t_max_;
	int max_tools_ = 3; // Always default of a max of 3 rented tools
	int num_rentals_ = 0;
	std::vector<Rental*> rentals_;
};

class Casual: public Customer {
	// rent 1 or 2 tools for 1 or 2 nights
	Casual();
};

class Business: public Customer {
	// rent 3 tools for 7 nights
	Business();
};

class Regular: public Customer {
	// rent 1- 3 tools for 3-5 nights
	Customer();
};
