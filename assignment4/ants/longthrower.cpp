#include "longthrower.hpp"

LongThrower::LongThrower() {
    this->symbol = 'L';
    this->armor = 1;
    this->food = 3;
}

void LongThrower::action(Board& b) {
    int dest = this->index + 4 < BOARD_SIZE ? this->index + 4 : -1;
    if (dest != -1) {
        Bee* bee;
        bool found_bee = false;
        do {
            if (dest == -1) break;

            for (unsigned int i = 0; i < b.b[dest].size(); i++) {
                bee = dynamic_cast<Bee*>(b.b[dest][i]);
                if (bee) {
                    found_bee = true;
                    bee->set_armor(bee->get_armor() - 1);
                }
            }

            dest = dest + 1 < BOARD_SIZE ? dest + 1 : -1;
        } while (!found_bee);
    }
}