#include "customerFactory.h"

customer* CustomerFactory::createCasual(std::string name) {
  return new Casual(name);
}

customer* CustomerFactory::createBusiness(std::string name) {
  return new Business(name);
}

customer* CustomerFactory::createRegular(std::string name) {
  return new Regular(name);
}

customer* CustomerFactory::createRandom(std::string name) {
  int r = rand() % 3 + 1;
  if (r == 1) {
    return createCasual(name);
  }
  if (r == 2) {
    return createBusiness(name);
  }
  if (r == 3) {
    return createRegular(name);
  }
  return createCasual(name);
}
