#ifndef FIRE_HPP_HPP
#define FIRE_HPP_HPP

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class Fire : public Ant {
public:
    Fire();

    void action(Board&);
};

#endif