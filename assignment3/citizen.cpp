#include "citizen.hpp"

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Citizen::Citizen() {
    this->budget = (rand() % (max_budget - min_budget) / 100) + min_budget;
}