#include "ninja.hpp"

Ninja::Ninja() {
    this->symbol = 'N';
    this->armor = 1;
    this->food = 6;
}

void Ninja::action(Board& b) {
    for (unsigned int i = 0; i < b.b[this->index].size(); i++) {
        Bee *bee;
        bee = dynamic_cast<Bee*>(b.b[this->index][i]);
        if (bee) {
            bee->set_armor(bee->get_armor() - 1);
        }
    }
}