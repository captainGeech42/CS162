#ifndef THROWER
#define THROWER

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class Thrower : public Ant {
public:
    Thrower();

    void action(Board&);
};

#endif