#ifndef TEMPLATE
#define TEMPLATE

#include "../ant.hpp"
#include "../entity.hpp"

class Template : public Ant {
public:
    Template();

    void action(Board&);
};

#endif