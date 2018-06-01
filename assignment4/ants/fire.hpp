#ifndef FIRE
#define FIRE

#include "../ant.hpp"
#include "../bee.hpp"
#include "../entity.hpp"

class Fire : public Ant {
public:
    Fire();

    void action(Board&);
};

#endif