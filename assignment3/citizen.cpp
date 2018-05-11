#include "citizen.hpp"

Citizen::Citizen() {
    this->budget = (rand() % (max_budget - min_budget) / 100) + min_budget;
}