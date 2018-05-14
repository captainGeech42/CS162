#include "tenant.hpp"

Tenant::Tenant() {
    this->agreeability = (rand() % 5) + 1;
    this->rent = -1;
}

int Tenant::get_budget() const { return this->budget; }
int Tenant::get_rent() const { return this->rent; }

void Tenant::set_rent(int rent) {
    this->rent = rent;
}

bool Tenant::will_pay_rent() {
    assert(this->rent > 0);
    return this->rent <= budget;
}

bool Tenant::will_leave() {
    return this->agreeability >= 3;
}