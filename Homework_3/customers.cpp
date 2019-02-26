#include <string>
#include <vector>
#include "customers.h"

Casual::Casual(std::string name): Customer(name,1,2,1,1){
}

Business::Business(std::string name) :Customer(name,3,3,7,7){
}

Regular::Regular(std::string name):Customer(name,1,3,3,5) {
}

Customer::Customer(std::string name, int n_min, int n_max, int t_min, int t_max) {
  name_ = name;
  n_min_ = n_min;
  n_max_ = n_max;
  t_min_ = t_min;
  t_max_ = t_max;
    max_tools_ = 3;
    num_rentals_ = 0;
}

void Customer::purchaseTools(Store* s, int cur_date) {
  Rental* cur_rental = rentalFactory::rentTools(s,n_min_,n_max_,t_min_,max_tools_-num_rentals_, cur_date);
  rentals_.push_back(cur_rental);
}

std::vector<Rental*> Customer::returnTools(int date) {
  std::vector<Rental*> returns;
  // check each rental in the customer's vector to see if it should be returned
  for (int i=0; i<rentals_.size(); i++) {
    if (rentals_[i]->getDueDate() == date) {
      returns.push_back(rentals_[i]);
      rentals_.erase(rentals_.begin()+i);
    }
  }
  return returns;
}

bool Customer::canRent() {
    if(num_rentals_ < max_tools_){
        return true;
    }else{
        return false;
    }
}
