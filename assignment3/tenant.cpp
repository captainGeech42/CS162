#include "tenant.hpp"

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tenant::Tenant() {
    this->agreeability = (rand() % 5) + 1;
    this->rent = -1;
}

int Tenant::get_budget() const { return this->budget; }
int Tenant::get_rent() const { return this->rent; }

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Tenant::set_rent(int rent) {
    this->rent = rent;
}

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Tenant::will_pay_rent() {
    assert(this->rent > 0);
    return this->rent <= budget;
}

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Tenant::will_leave() {
    return this->agreeability >= 3;
}