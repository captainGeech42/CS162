#ifndef CITIZEN
#define CITIZEN

#include "tenant.hpp"

class Citizen : public Tenant {
private:
    const static int min_budget = 500;
    const static int max_budget = 5000;

public:
    Citizen();
};

#endif