#include "property.hpp"

Property::Property() {
    this->location = static_cast<Location>(rand() % 5);

    this->mortgage_amount = (rand() % (this->max_mortgage - 1000) / 10) * 10;
    this->mortgage_amount_paid = 0;
}

Property::~Property() {
    for (int i = 0; i < this->tenants.get_size(); i++) {
        delete this->tenants[i];
    }
}

int Property::collect_rent() {
    int total_rent = 0;
    for (int i = 0; i < num_tenants; i++) {
        if (this->tenants[i]->will_pay_rent()) {
            total_rent += this->tenants[i]->get_rent();
        }
    }

    return total_rent;
}

void Property::set_rents() {
    int lowest = 50000; // garbage value, just an arbitrary big number
    for (int i = 0; i < this->num_tenants; i++) {
        if (this->tenants[i]->get_budget() < lowest) {
            lowest = this->tenants[i]->get_budget();
        }
    }

    for (int i = 0; i < this->num_tenants; i++) {
        this->tenants[i]->set_rent(lowest);
    }
}

int Property::pay_mortgage() {
    if (this->mortgage_amount_paid < this->mortgage_amount) {
        this->mortgage_amount_paid += this->mortgage_amount;
        this->mortgage_months_remaining--;
        return this->mortgage_amount;
    }
    return 0;
}

int Property::get_value() const { return this->value; }

void Property::update_tenants() {
    for (int i = 0; i < this->tenants.get_size(); i++) {
        if (!this->tenants[i]->will_pay_rent() && this->tenants[i]->will_leave()) {
            this->tenants.erase(i);
            return update_tenants();
        }
    }
}

void Property::print() {
    printf("Location: ");
    switch (this->location) {
        case kSoutheast:
            printf("SE");
            break;
        case kNortheast:
            printf("NE");
            break;
        case kMidwest:
            printf("Midwest");
            break;
        case kSouthwest:
            printf("SW");
            break;
        case kNorthwest:
            printf("NW");
            break;
    }
    printf(" | Value: %d\n", this->value);

    printf("Mortgage Cost: %d | Mortgage Duration: %d\n", this->mortgage_amount, this->mortgage_duration);

    if (this->mortgage_amount_paid != 0) {
        printf("Mortgage Amount Paid: %d\n", this->mortgage_amount_paid);
    }

    if (this->tenants.get_size() == 0) {
        printf("No tenants are currently occupying this property.\n");
    } else {
        printf("Tenant Information:\n");
        for (int i = 0; i < this->tenants.get_size(); i++) {
            printf("\tTenant #%d | Rent: %d | Budget: %d\n", i+1, this->tenants[i]->get_rent(), this->tenants[i]->get_budget());
        }
    }
}

void Property::do_event(Event event) {
    assert(event != kGentrification);

    switch (event) {
        case kHurricane:
            if (this->location == kSoutheast) this->value *= 0.5;
            break;
        case kStockMarket:
            this->value *= 0.7;
            break;
        case kWildfire:
            if (this->location == kSouthwest) this->value *= 0.75;
            break;
        case kEarthquake:
            if (this->location == kNorthwest) this->value *= 0.9;
            break;
        case kTornado:
            if (this->location == kMidwest) this->value *= 0.7;
            break;
        case kGentrification:
            // will never happen
            break;
    }
}

void Property::do_gentrification(Location location) {
    if (this->location == location) this->value *= 1.2;
}

void Property::update_rent() {
    // intentionally empty
    return;
}

int Property::get_total_rent() {
    int rent = 0;
    for (int i = 0; i < this->tenants.get_size(); i++) {
        if (this->tenants[i]->will_pay_rent()) {
            rent += this->tenants[i]->get_rent();
        }
    }

    return rent;
}

int Property::get_mortgage() const { 
    if (this->mortgage_months_remaining > 0) {
        return this->mortgage_amount;
    }
    return 0;
}