#ifndef WALL
#define WALL

#include "../ant.hpp"
#include "../entity.hpp"

class Wall : public Ant {
public:
    Wall();

    void action(Board&);
};

#endif