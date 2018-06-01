#ifndef BODYGUARD
#define BODYGUARD

#include "../ant.hpp"
#include "../entity.hpp"

class Bodyguard : public Ant {
public:
    Bodyguard();

    void action(Board&);
};

#endif