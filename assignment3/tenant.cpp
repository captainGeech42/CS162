#include "tenant.hpp"

Tenant::Tenant() {
    this->agreeability = rand() % 5 + 1;
}

bool Tenant::will_pay_rent(int rent) {
    return rent <= budget;
}

bool Tenant::will_leave() {
    return this->agreeability >= 3;
}