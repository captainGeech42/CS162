#include "business.hpp"

Business::Business() {
    this->budget = (rand() % (max_budget - min_budget)) + min_budget;

    this->size = kSmall;
    this->rent = -1;
}