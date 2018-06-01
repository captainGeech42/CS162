#ifndef SHORTTHROWER_HPP_HPP
#define SHORTTHROWER_HPP_HPP

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class ShortThrower : public Ant {
public:
    ShortThrower();

    void action(Board&);
};

#endif