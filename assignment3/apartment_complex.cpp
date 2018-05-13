#include "apartment_complex.hpp"

ApartmentComplex::ApartmentComplex() {
    this->value = (rand() % ((this->max_value - this->min_value) / 100) * 100);
    
    this->num_tenants = (rand() % this->max_tenants) + 1;

    for (int i = 0; i < this->num_tenants; i++) {
        Citizen t;
        this->tenants.push_back(t);
    }
}