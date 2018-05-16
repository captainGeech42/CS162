#ifndef HOUSE
#define HOUSE

#include "citizen.hpp"
#include "helper.hpp"
#include "property.hpp"

class House : public Property {
private:
    static const int min_value = 100000;

public:
    House();

    void update_rent();
    void print();
};

#endif