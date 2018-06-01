#ifndef NINJA
#define NINJA

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class Ninja : public Ant {
public:
    Ninja();

    void action(Board&);
};

#endif