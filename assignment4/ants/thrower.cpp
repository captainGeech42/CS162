#include "thrower.hpp"

Thrower::Thrower() {
    this->symbol = '%';
    this->armor = 42;
    this->food = 69;
}

void Thrower::action(Board& b) {
    Bee *bee;
    for (unsigned int i = 0; i < b.b[this->index].size(); i++) {
        bee = dynamic_cast<Bee*>(b.b[this->index][i]);
        if (bee) {
            bee->set_armor(bee->get_armor() - 1);
            return;
        }
    }
}