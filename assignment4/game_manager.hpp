#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "ant.hpp"
#include "ants/ants.hpp"
#include "board.hpp"
#include "bee.hpp"
#include "ui_manager.hpp"

#ifdef MAKE
#include "helper.hpp"
#else
#include "O:\cpphelper\helper.hpp"
#endif

class GameManager {
private:
    Board b;
    UIManager ui;

    void add_bee();
    void add_ant();
    bool can_place(int, Ant::Type);

public:
    enum State {
        RUNNING,
        WIN,
        LOSE
    };

    GameManager();

    State get_state();
    void next_turn();
};

#endif