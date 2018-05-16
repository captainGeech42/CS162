#ifndef APARTMENT_COMPLEX
#define APARTMENT_COMPLEX

#include <stdlib.h>

#include "property.hpp"
#include "citizen.hpp"

#ifdef MAKE
#include "helper.hpp"
#else
#include "O:\cpphelper\helper.hpp"
#endif

class ApartmentComplex : public Property {
private:
    const static int min_value = 300000;
    const static int max_tenants = 10;

public:
    ApartmentComplex();

    void update_rent();
};

#endif
