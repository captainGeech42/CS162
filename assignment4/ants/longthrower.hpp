#ifndef LONGTHROWER
#define LONGTHROWER

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class LongThrower : public Ant {
public:
    LongThrower();

    void action(Board&);
};

#endif