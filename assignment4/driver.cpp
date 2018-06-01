#include "game_manager.hpp"

#include <stdio.h>

int main() {
    GameManager gm;
    GameManager::State state;

    do {
        gm.next_turn();
    } while ((state = gm.get_state()) == GameManager::RUNNING);

    switch (state) {
        case GameManager::WIN:
            printf("Congratulations, you win!\n");
            break;
        case GameManager::LOSE:
            printf("Congratulations, you're really bad at this game!\n");
            break;
        default:
            return 1;
    }

    return 0;
}
