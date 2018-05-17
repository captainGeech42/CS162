#include "apartment_complex.hpp"

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
ApartmentComplex::ApartmentComplex() {
    this->value = (rand() % ((this->max_value - this->min_value) / 100) * 100);
    this->mortgage_duration = ceil((float)this->value/(float)this->mortgage_amount);
    this->mortgage_months_remaining = this->mortgage_months_remaining;
    
    this->num_tenants = (rand() % this->max_tenants) + 1;

    for (int i = 0; i < this->num_tenants; i++) {
        Citizen* t = new Citizen;
        this->tenants.push_back(t);
    }

    this->set_rents();
}

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void ApartmentComplex::update_rent() {
    int rent;
    do {
        rent = get_int("Please enter a new rent: ");
    } while (rent < 0);

    for (int i = 0; i < this->tenants.get_size(); i++) {
        this->tenants[i]->set_rent(rent);
    }
}

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void ApartmentComplex::print() {
    printf("Property type: Apartment Complex\n");

    Property::print();
}