#include "business.hpp"

Business::Business() {
    this->budget = (rand() % (max_budget - min_budget) / 100) + min_budget;

    this->size = kSmall;
    this->rent = -1;
}