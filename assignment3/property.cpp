#include "property.hpp"

Property::Property() {
    this->location = static_cast<Location>(rand() % 5);
    
}

// intentionally empty
void Property::collect_rent() { return; }