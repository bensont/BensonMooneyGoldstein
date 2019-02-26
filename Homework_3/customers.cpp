#include <string>
#include <vector>

Customer* Casual::Casual(std::string name) {
  Customer* new_customer = new Customer(name,1,2,1,1);
  return new_customer;
}

Business::Business(std::string name) {
  Customer* new_customer = new Customer(name,3,3,7,7);
  return new_customer;
}

Regular::Regular(std::string name) {
  Customer* new_customer = new Customer(name,1,3,3,5);
  return new_customer;
}

Customer::Customer(std::string name, int n_min, int n_max, int t_min, int t_max) {
  name_ = name;
  n_min_ = n_min;
  n_max_ = n_max;
  t_min_ = t_min;
  t_max_ = t_max;
}

void Customer::purchaseTools(Store* s, int cur_date) {
  Rental* cur_rental = rentalFactory::rentTools(s,n_min_,n_max_,t_min_,max_tools_-num_rentals_, cur_date);
  rentals_.push_back(cur_rental);
}

std::vector<Rental*> Customer::returnTools(int date) {
  std::vector<Rental> returns;
  // check each rental in the customer's vector to see if it should be returned
  for (int i=0; i<rentals_.size(); i++) {
    if (rentals_[i].dueDate == date) {
      returns.push_back(rentals_[i]);
      rentals_.erase(i);
    }
  }
  return returns;
}

bool Customer::canRent() {
  return if(num_rentals_ < max_tools_);
}
