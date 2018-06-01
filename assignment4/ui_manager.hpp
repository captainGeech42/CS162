#ifndef UI_MANAGER
#define UI_MANAGER

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "ant.hpp"
#include "bee.hpp"
#include "board.hpp"

class UIManager {
private:
    Board b;

    int get_max_height();

public:
    UIManager() {}
    UIManager(Board&);

    void print();
};

#endif