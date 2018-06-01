#ifndef THROWER_HPP_HPP
#define THROWER_HPP_HPP

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class Thrower : public Ant {
public:
    Thrower();

    void action(Board&);
};

#endif