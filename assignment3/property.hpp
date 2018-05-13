#ifndef PROPERTY
#define PROPERTY

#include <stdlib.h>

#include "list.hpp"
#include "tenant.hpp"

#define PROPERTY_TAX 0.015

class Property {
public:
    enum Location {
        kSoutheast,
        kNortheast,
        kMidwest,
        kSouthwest,
        kNorthwest
    };

    Property();
    
    virtual void collect_rent();

    Property& generate_property();

protected:
    static const int max_mortgage = 5000;
    static const int max_value = 600000;

    Location location;
    List<Tenant> tenants;
    int num_tenants, value, mortgage_amount, mortgage_duration;
};

#endif