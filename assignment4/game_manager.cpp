#include "game_manager.hpp"

GameManager::GameManager() {
    this->ui = UIManager(b);
}

void GameManager::add_bee() {
    this->b.b[9].push_back(new Bee);
}

void GameManager::add_ant() {
    printf("1. Harvester\t\t5. Short Thrower\n");
    printf("2. Thrower\t\t6. Wall\n");
    printf("3. Fire\t\t7. Ninja\n");
    printf("4. Long Thrower\t\t8. Bodyguard\n");

    int type;
    do {
        type = get_int("Please select the type of ant to place: ");
    } while (type < 1 || type > 8);

    int location;
}

bool GameManager::can_place(int location, Ant::Type type) {
    Ant* ant;
    
    bool can_place = true;
    for (unsigned int i = 0; i < this->b.b[location].size(); i++) {
        ant = dynamic_cast<Ant*>(this->b.b[location][i]);
        if (ant) {
            
        }
    }
}

GameManager::State GameManager::get_state() {
    bool bees_left = false;

    Bee *b;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->b.b[i].size(); j++) {
            b = dynamic_cast<Bee*>(this->b.b[i][j]);
            if (b) {
                bees_left = true;
                break;
            }
        }
        if (bees_left) break;
    }

    if (!bees_left) return WIN;

    for (unsigned int i = 0; i < this->b.b[0].size(); i++) {
        b = dynamic_cast<Bee*>(this->b.b[0][i]);
        if (b) return LOSE;
    }

    return RUNNING;
}

void GameManager::next_turn() {
    this->ui.print();
}