#ifndef HOUSE
#define HOUSE

#include "citizen.hpp"
#include "property.hpp"

class House : public Property {
private:
    static const int min_value = 100000;

public:
    House();
};

#endif