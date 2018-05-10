#ifndef PROPERTY
#define PROPERTY

#include "list.hpp"
#include "tenant.hpp"

class Property {
public:
    enum Location {
        kSoutheast,
        kNortheast,
        kMidwest,
        kSouthwest,
        kNorthwest
    };
    
    virtual void collect_rent() = 0;

protected:
    Location location;
    static int min_cost;
    const static int max_cost = 600000;
    constexpr static float property_tax = 0.015;
    List<Tenant> tenants;
    static int max_tenants;
    int mortgage;
};

#endif