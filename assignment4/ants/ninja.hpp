#ifndef NINJA_HPP_HPP
#define NINJA_HPP_HPP

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class Ninja : public Ant {
public:
    Ninja();

    void action(Board&);
};

#endif