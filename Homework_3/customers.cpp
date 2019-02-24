#include <string>
#include <vector>

Casual::Casual(std::string name) {
  name_ = name;
  n_min_ = 1;
  n_max_ = 2;
  t_min_ = 1;
  t_max_ = 1;
}

Casual::Business(std::string name) {
  name_ = name;
  n_min_ = 3;
  n_max_ = 3;
  t_min_ = 7;
  t_max_ = 7;
}

Casual::Regular(std::string name) {
  name_ = name;
  n_min_ = 1;
  n_max_ = 3;
  t_min_ = 3;
  t_max_ = 5;
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
