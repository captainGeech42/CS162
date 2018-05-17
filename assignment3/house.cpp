#include "house.hpp"

House::House() {
    this->value = (rand() % ((this->max_value - this->min_value) / 100) * 100);
    this->mortgage_duration = ceil((float)this->value/(float)this->mortgage_amount);
    this->mortgage_months_remaining = this->mortgage_months_remaining;

    this->num_tenants = 1;
    Citizen* t = new Citizen;
    this->tenants.push_back(t);
    
    this->set_rents();
}

void House::update_rent() {
    int rent;
    do {
        rent = get_int("Please enter a new rent: ");
    } while (rent < 0);

    this->tenants[0]->set_rent(rent);
}

void House::print() {
    printf("Property type: House\n");

    Property::print();
}