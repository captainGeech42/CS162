#include "house.hpp"

House::House() {
    this->value = (rand() % ((this->max_value - this->min_value) / 100) * 100);

    this->num_tenants = 1;
    Citizen t;
    this->tenants.push_back(t);

    this->set_rents();
}