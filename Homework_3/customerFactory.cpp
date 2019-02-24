#include "customerFactory.h"

customer* CustomerFactory::createCasual(std::string name) {
  return new Casual(name);
}

customer* CustomerFactory::createBusiness() {
  return new Business(name);
}

customer* CustomerFactory::createRegulaer() {
  return new Regular(name);
}
