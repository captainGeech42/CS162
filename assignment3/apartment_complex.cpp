#include "apartment_complex.hpp"

ApartmentComplex::ApartmentComplex() {
    this->value = (rand() % ((this->max_value - this->min_value) / 100) * 100);
    
    this->num_tenants = (rand() % this->max_tenants) + 1;

    for (int i = 0; i < this->num_tenants; i++) {
        Citizen t;
        this->tenants.push_back(t);
    }

    this->set_rents();
}

void ApartmentComplex::update_rent() {
    int rent;
    do {
        rent = get_int("Please enter a new rent: ");
    } while (rent < 0);

    for (int i = 0; i < this->tenants.get_size(); i++) {
        this->tenants[i].set_rent(rent);
    }
}

void ApartmentComplex::print() {
    printf("Property type: Apartment Complex\n");

    Property::print();
}