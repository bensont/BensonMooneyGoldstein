#pragma once
#include "customers.h"

class CustomerFactory{
public:
  static Customer* createCasual(std::string name);
  static Customer* createBusiness(std::string name);
  static Customer* createRegular(std::string name);
  static Customer* createRandom(std::string name);
};
