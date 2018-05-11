#ifndef PROPERTY
#define PROPERTY

#include "list.hpp"
#include "tenant.hpp"

#define PROPERTY_TAX 0.015
#define MAX_MORTGAGE 5000
#define MAX_PROPERTY_VALUE 600000

class Property {
public:
    enum Location {
        kSoutheast,
        kNortheast,
        kMidwest,
        kSouthwest,
        kNorthwest
    };
    
    virtual void collect_rent();

    Property& generate_property();

protected:
    Location location;
    List<Tenant> tenants;
    int mortgage_amount;
    int mortgage_duration;
};

#endif