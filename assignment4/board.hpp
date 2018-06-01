#ifndef BOARD
#define BOARD

#define BOARD_SIZE 10

#include <vector>

#include "entity.hpp"

struct Board {
    std::vector<Entity*> b[BOARD_SIZE];
    int food;
};

#endif
