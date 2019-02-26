#pragma once
#include <vector>
#include <string>
#include "rental.h"
#include "rentalFactory.h"
#include "store.h"

class Customer{
public:
    ~Customer();
    void purchaseTools(Store* s, int cur_date);
    std::vector<Rental*> returnTools(int date);
	bool canRent();
    void display();
protected:
    Customer(std::string name, int n_min, int n_max, int t_min, int t_max);
private:
	std::string name_;
	int n_min_; // rental min/max nights
	int n_max_;
	int t_min_; // tool min/max rented
	int t_max_;
	int max_tools_; // Always default of a max of 3 rented tools
	int num_rentals_;
	std::vector<Rental*> rentals_;
};

class Casual: public Customer {
	// rent 1 or 2 tools for 1 or 2 nights
public:
    Casual(std::string name);
};

class Business: public Customer {
	// rent 3 tools for 7 nights
public:
	Business(std::string name);
};

class Regular: public Customer {
	// rent 1- 3 tools for 3-5 nights
public:
	Regular(std::string name);
};
