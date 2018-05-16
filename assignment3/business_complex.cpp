#include "business_complex.hpp"

BusinessComplex::BusinessComplex() {
    this->value = (rand() % ((this->max_value - this->min_value) / 100) * 100);

    this->num_tenants = (rand() % this->max_tenants) + 1;
    for (int i = 0; i < this->num_tenants; i++) {
        Business t;
        this->tenants.push_back(t);
    }

    this->set_rents();
}

int BusinessComplex::collect_rent() {
#ifdef DEBUG
    printf("in BusinessComplex::collect_rent()\n");
#endif
    
    for (int i = 0; i < this->num_tenants; i++) {
        if (this->tenants[i].will_pay_rent()) {
            this->value *= PROPERTY_VALUE_INCREASE;
        }
    }

    return Property::collect_rent();
}

void BusinessComplex::update_rent() {
    int tenant;
    do {
        tenant = get_int("Please enter which tenant you would like to change the rent for: ");
    } while (tenant < 0 || tenant >= this->tenants.get_size());

    int rent;
    do {
        printf("Please enter the new rent for tenant #%d: ", tenant);
        rent = get_int("");
    } while (rent < 0);

    this->tenants[tenant].set_rent(rent);
}

void BusinessComplex::print() {
    printf("Property type: Business Complex\n");

    Property::print();
}