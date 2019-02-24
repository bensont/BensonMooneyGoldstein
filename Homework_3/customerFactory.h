#pragma once
#include "customers.h"

static class CustomerFactory{
  customer* createCasual(std::string name);
  customer* createBusiness(std::string name);
  customer* createRegulaer(std::string name);
  customer* createRandom(std::string name);
};
