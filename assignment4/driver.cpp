#include "game_manager.hpp"

int main() {
    GameManager gm;
    GameManager::State state;

    do {
        gm.next_turn();
    } while ((state = gm.get_state()) == GameManager::RUNNING);

}
