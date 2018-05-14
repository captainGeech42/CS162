#ifndef BUSINESS_COMPLEX
#define BUSINESS_COMPLEX

#include <stdlib.h>

#include "property.hpp"
#include "business.hpp"

#define PROPERTY_VALUE_INCREASE 1.01

class BusinessComplex : public Property {
private:  
    static const int min_value = 400000;
    static const int max_tenants = 5;

public:
    BusinessComplex();

    int collect_rent();
};

#endif
