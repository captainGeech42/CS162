#ifndef WALL_HPP_HPP
#define WALL_HPP_HPP

#include "../ant.hpp"
#include "../entity.hpp"

class Wall : public Ant {
public:
    Wall();

    void action(Board&);
};

#endif