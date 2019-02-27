#include <string>
#include <vector>
#include <iostream>
#include "customers.h"

Casual::Casual(std::string name): Customer(name,1,2,1,1,"casual"){
}

Business::Business(std::string name) :Customer(name,3,3,7,7,"business"){
}

Regular::Regular(std::string name):Customer(name,1,3,3,5,"regular") {
}

Customer::Customer(std::string name, int t_min, int t_max, int n_min, int n_max,std::string type) {
  name_ = name;
  n_min_ = n_min; //min number of nights
  n_max_ = n_max;
  t_min_ = t_min; //min number of tools
  t_max_ = t_max;
    max_tools_ = 3;
    num_rentals_ = 0;
    type_ = type; //transition to polymorphism
}

//When a customer is deleted, delete its rentals
Customer::~Customer(){
    rentals_.clear();
}

void Customer::purchaseTools(Store* s, int cur_date) {
    int numRentals;
    numRentals = max_tools_-num_rentals_; //Find the true maximum number of tools to rent (generally 3-current
    if(numRentals > t_max_){
        numRentals = t_max_; //for casuals it might actually be min 2
    }
  Rental* cur_rental = rentalFactory::rentTools(s,n_min_,n_max_,t_min_,numRentals, cur_date);
    //Make sure the rental is both not null and not empty (like business with only two available)
    if(cur_rental != NULL && !cur_rental->isEmpty()){
        rentals_.push_back(cur_rental); //add too array
        num_rentals_ += cur_rental->numTools(); //increase number of tools
    }
}

std::vector<Rental*> Customer::returnTools(int date) {
  std::vector<Rental*> returns;
  // check each rental in the customer's vector to see if it should be returned
  for (int i=0; i<rentals_.size(); i++) {
    if (rentals_[i]->getDueDate() == date) {
      returns.push_back(rentals_[i]); //copy pointer
      rentals_.erase(rentals_.begin()+i); //remove raw pointer from the vector
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

void Customer::display(){
    display_();
}

//protected version of display
void Customer::display_(){
    std::cout << name_ << " " << type_ << " " << std::endl;
    if(rentals_.size() != 0){
        
        for(int i=0;i<rentals_.size();i++){
            std::cout << "Rental " << std::to_string(i+1) << std::endl;
            rentals_.at(i)->display();
        }
    }
}

/*
void Regular::display(){
    std::cout << "I'm a regular";
    display_();
    std::cout << std::endl;
}

void Casual::display(){
    std::cout << "Casual dude";
    display_();
    std::cout << std::endl;
}

void Business::display(){
    std::cout << "Business";
    display_();
    std::cout << std::endl;
}
 */
