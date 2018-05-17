#include "business.hpp"

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Business::Business() {
    this->budget = (rand() % (max_budget - min_budget)) + min_budget;

    this->size = kSmall;
    this->rent = -1;
}