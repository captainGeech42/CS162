#ifndef SHORTTHROWER
#define SHORTTHROWER

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class ShortThrower : public Ant {
public:
    ShortThrower();

    void action(Board&);
};

#endif