#ifndef HARVESTER
#define HARVESTER

#include "../ant.hpp"
#include "../entity.hpp"

class Harvester : public Ant {
public:
    Harvester();

    void action(Board&);
};

#endif