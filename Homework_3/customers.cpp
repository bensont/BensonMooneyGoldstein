#include "customers.h"

Casual::Casual(std::string name): Customer(name,1,2,1,1,"casual"){
    Logger::print("Created Casual Customer",info2);
}

Business::Business(std::string name): Customer(name,3,3,7,7,"business"){
    Logger::print("Created Business Customer",info2);
}

Regular::Regular(std::string name): Customer(name,1,3,3,5,"regular") {
    Logger::print("Created Regular Customer",info2);
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
    //bool didReturn = false;
  std::vector<Rental*> returns;
  // check each rental in the customer's vector to see if it should be returned
    //because we are deleting this must be done back to front
    if(rentals_.size() == 0){
        return returns;
    }
    int i = 0;
    //for(int i = )
        if(rentals_.at(i)->getDueDate() == date){
            //rentals_.at(i)->display();
            returns.push_back(rentals_.at(i)); //copy pointer
            //deal with extra book keeping
            num_rentals_ -= rentals_[i]->numTools();
        rentals_.erase(rentals_.begin()+i); //remove raw pointer from the vector
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
    //std::cout << name_ << " " << type_ << " " << std::endl;
    display_();
}

//protected version of display
void Customer::display_(){
    Logger::print(name_ + " " + type_,message);
    if (rentals_.size() != 0){
        for(int i=0;i < rentals_.size();i++){
            Logger::print("Rental "+std::to_string(i+1)+ " Due on day"+std::to_string(rentals_.at(i)->getDueDate()),message);
            rentals_.at(i)->display();
        }
        
    }
}

/*
 //This should be implemented
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
