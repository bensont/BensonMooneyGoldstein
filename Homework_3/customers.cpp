#include <string>

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
