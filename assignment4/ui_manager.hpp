#ifndef UI_MANAGER
#define UI_MANAGER

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "ant.hpp"
#include "bee.hpp"
#include "board.hpp"
#include "entity.hpp"

class UIManager {
private:
    enum Color {
	GREEN=92,
	YELLOW=93,
	RED=91,
	BKGD=40 // black
    };

    int get_max_height(Board&);
    void set_color(Entity*);
    void reset_color();

public:
    void print(Board&);
};

#endif
