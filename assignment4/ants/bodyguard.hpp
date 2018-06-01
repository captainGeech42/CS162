#ifndef BODYGUARD_HPP_HPP
#define BODYGUARD_HPP_HPP

#include "../ant.hpp"
#include "../entity.hpp"

class Bodyguard : public Ant {
public:
    Bodyguard();

    void action(Board&);
};

#endif