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
    Business(const Business&);
    ~Business();

    const Business& operator=(const Business&);

private:
    int rent;
    Size size;

    int min_budget = 2000;
    int max_budget = 10000;
};

#endif