#ifndef PROPERTY
#define PROPERTY

#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "event.hpp"
#include "list.hpp"
#include "tenant.hpp"

#define PROPERTY_TAX 0.015

class Property {
public:
    Property();

    enum Location {
        kSoutheast,
        kNortheast,
        kMidwest,
        kSouthwest,
        kNorthwest
    };
    
    virtual int collect_rent();
    int pay_mortgage();
    int get_value() const;
    void update_tenants();
    void print();
    void do_event(Event);
    void do_gentrification(Location);
    virtual void update_rent();

protected:
    static const int max_mortgage = 5000;
    static const int max_value = 600000;

    Location location;
    List<Tenant> tenants;
    int num_tenants, value, mortgage_amount, mortgage_duration, mortgage_amount_paid;
    
    void set_rents();
};

#endif