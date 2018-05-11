#ifndef BUSINESS
#define BUSINESS

#include "tenant.hpp"

class Business : public Tenant {
public:
    enum Size {
        kSmall,
        kMedium,
        kLarge
    };

    Business();

private:
    int rent;
    Size size;

    const static int min_budget = 2000;
    const static int max_budget = 10000;
};

#endif