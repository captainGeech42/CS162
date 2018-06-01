#include "fire.hpp"

Fire::Fire() {
    this->symbol = 'F';
    this->armor = 1;
    this->food = 4;
}

void Fire::action(Board& b) {
    if (this->armor < 1) {
        Bee *bee;
        for (unsigned int i = 0; i < b.b[index].size(); i++) {
            bee = dynamic_cast<Bee*>(b.b[index][i]);
            if (bee) {
                b.b[index].erase(b.b[index].begin() + i);
                i = 0;
            }
        }
    }
}