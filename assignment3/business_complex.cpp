#include "business_complex.hpp"

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
BusinessComplex::BusinessComplex() {
    this->value = (rand() % ((this->max_value - this->min_value) / 100) * 100);
    this->mortgage_duration = ceil((float)this->value/(float)this->mortgage_amount);
    this->mortgage_months_remaining = this->mortgage_months_remaining;

    this->num_tenants = (rand() % this->max_tenants) + 1;
    for (int i = 0; i < this->num_tenants; i++) {
        Business* t = new Business;
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
int BusinessComplex::collect_rent() {
#ifdef DEBUG
    printf("in BusinessComplex::collect_rent()\n");
#endif
    
    for (int i = 0; i < this->tenants.get_size(); i++) {
        if (this->tenants[i]->will_pay_rent()) {
            this->value *= PROPERTY_VALUE_INCREASE;
        }
    }

    return Property::collect_rent();
}

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void BusinessComplex::update_rent() {
    int tenant;
    do {
        tenant = get_int("Please enter which tenant you would like to change the rent for: ") - 1;
    } while (tenant < 0 || tenant >= this->tenants.get_size());

    int rent;
    do {
        printf("Please enter the new rent for tenant #%d: ", tenant);
        rent = get_int("");
    } while (rent < 0);

    this->tenants[tenant]->set_rent(rent);
}

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void BusinessComplex::print() {
    printf("Property type: Business Complex\n");

    Property::print();
}

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void BusinessComplex::set_rents() {
    for (int i = 0; i < this->tenants.get_size(); i++) {
        this->tenants[i]->set_rent((rand() % (Business::max_budget - Business::min_budget)) + Business::min_budget);
    }
}