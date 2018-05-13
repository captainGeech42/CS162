#ifndef APARTMENT_COMPLEX
#define APARTMENT_COMPLEX

#include <stdlib.h>

#include "property.hpp"
#include "citizen.hpp"

class ApartmentComplex : public Property {
private:
    const static int min_value = 300000;
    const static int max_tenants = 10;

public:
    ApartmentComplex();
};

#endif
