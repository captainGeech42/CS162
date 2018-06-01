#ifndef ANT
#define ANT

#include "board.hpp"
#include "entity.hpp"

class Ant : public Entity {
protected:
    int food;
    Ant();

public:
    enum Type {
        HARVESTER,
        THROWER,
        FIRE,
        LONG_THROWER,
        SHORT_THROWER,
        WALL,
        NINJA,
        BODYGUARD
    };

    int get_food() const;

    virtual void action(Board&)=0;
};

#endif
