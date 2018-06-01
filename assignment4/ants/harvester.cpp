#include "harvester.hpp"

Harvester::Harvester() {
    this->symbol = 'H';
    this->armor = 1;
    this->food = 2;
}

void Harvester::action(Board& b) {
    b.food++;
}