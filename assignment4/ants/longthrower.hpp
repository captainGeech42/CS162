#ifndef LONGTHROWER_HPP_HPP
#define LONGTHROWER_HPP_HPP

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class LongThrower : public Ant {
public:
    LongThrower();

    void action(Board&);
};

#endif