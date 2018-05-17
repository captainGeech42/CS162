#include "game_manager.hpp"

GameManager::GameManager() {
    this->bank_account = 500000;
    this->months = 0;
}

GameManager::GameManager(const GameManager& rhs) {
    this->available_properties = rhs.available_properties;
    this->owned_properties = rhs.owned_properties;
    this->bank_account = rhs.bank_account;
}

GameManager::~GameManager() {
    for (int i = 0; i < this->available_properties.get_size(); i++) {
        delete this->available_properties[i];
    }
    for (int i = 0; i < this->owned_properties.get_size(); i++) {
        delete this->owned_properties[i];
    }
}

const GameManager& GameManager::operator=(const GameManager& rhs) {
    this->available_properties = rhs.available_properties;
    this->owned_properties = rhs.owned_properties;
    this->bank_account = rhs.bank_account;

    return *this;
}

int GameManager::get_bank_account() const { return this->bank_account; }

bool GameManager::is_game_over() {
    return this->bank_account <= 0 || this->bank_account >= 1000000;
}

void GameManager::generate_properties() {
    for (int i = 0; i < 3; i++) {
        Property *p;

        p = new House;
        this->available_properties.push_back(p);
        
        p = new ApartmentComplex;
        this->available_properties.push_back(p);
        
        p = new BusinessComplex;
        this->available_properties.push_back(p);
    }
}

void GameManager::pay_debts() {
    for (int i = 0; i < this->owned_properties.get_size(); i++) {
        this->bank_account -= this->owned_properties[i]->pay_mortgage();
    }
}

void GameManager::pay_taxes() {
    if (this->months % 12 == 0 && this->months != 0) {
        printf("It's your favorite month of the year! Time to pay taxes!\n");

        for (int i = 0; i < this->owned_properties.get_size(); i++) {
            this->bank_account -= this->owned_properties[i]->get_value() * PROPERTY_TAX;
        }
    }
    this->months++;
}

void GameManager::collect_rent() {
    for (int i = 0; i < this->owned_properties.get_size(); i++) {
        this->bank_account += this->owned_properties[i]->collect_rent();
    }
}

void GameManager::update_properties() {
    for (int i = 0; i < this->owned_properties.get_size(); i++) {
        this->owned_properties[i]->update_tenants();
    }
}

void GameManager::buy_property() {
    if (this->available_properties.get_size() == 0) {
        this->generate_properties();
    }

    if (get_yes_no("Would you like to buy a property? ")) {
        int one, two, three;
        one = rand() % this->available_properties.get_size();
        do {
            two = rand() % this->available_properties.get_size(); 
        } while (one == two);
        do {
            three = rand() % this->available_properties.get_size(); 
        } while (one == three && two == three);

        printf("Property #1:\n");
        this->available_properties[one]->print();
        printf("Property #2:\n");
        this->available_properties[two]->print();
        printf("Property #3:\n");
        this->available_properties[three]->print();

        int val;
        do {
            val = get_int("Which property would you like to buy? 1, 2, or 3? ");
        } while (val < 1 || val > 3);

        Property *prop;
        switch (val) {
            case 1:
                prop = this->available_properties[one];
                this->available_properties.erase(one);
                break;
            case 2:
                prop = this->available_properties[two];
                this->available_properties.erase(two);
                break;
            case 3:
                prop = this->available_properties[three];
                this->available_properties.erase(three);
                break;
        }
        this->owned_properties.push_back(prop);
    }
}

void GameManager::sell_property() {
    if (get_yes_no("Would you like to sell a property? ")) {
        this->print_owned();

        int index;
        do {
            index = get_int("Which property would you like to sell? ");
        } while (index < 0 || index >= this->owned_properties.get_size());

        int property_value = get_int("How much would you like to attempt to sell it for? ");

        switch (rand() % 3) {
            case 0:
                printf("You received 90%% of the property value.\n");
                this->bank_account += 0.9 * this->owned_properties[index]->get_value();
                break;
            case 1:
                printf("You received 100%% of the property value.\n");
                this->bank_account += this->owned_properties[index]->get_value();
                break;
            case 2:
                printf("You received your asking price.\n");
                this->bank_account += property_value;
                break;
        }

        this->owned_properties.erase(index);
    }
}

void GameManager::event() {
    Event event = static_cast<Event>(rand() % 6);
    Property::Location location;

    switch (event) {
        case kHurricane:
            printf("You have been struck by a hurricane! All properties in the SE lose 50%% value\n");
            break;
        case kStockMarket:
            printf("The stock market has crashed! All properties lose 30%% value\n");
            break;
        case kWildfire:
            printf("A wildfire has started! All properties in the SW lose 25%% value\n");
            break;
        case kEarthquake:
            printf("There was an earthquake! All properties in the NW lose 10%% value\n");
            break;
        case kTornado:
            printf("You have been struck by a tornado! All properties in the midwest lose 30%% v alue\n");
            break;
        case kGentrification:
            location = static_cast<Property::Location>(rand() % 5);
            switch (rand() % 3) {
                case 0:
                    printf("A big business has moved to town! ");
                    break;
                case 1:
                    printf("A natural resource was discovered! ");
                    break;
                case 2:
                    printf("There was a recent string of positive press for the city! ");
                    break;
            }

            switch (location) {
                case Property::kSoutheast:
                    printf("All properties in the SE gain 20%% value\n");
                    break;
                case Property::kNortheast:
                    printf("All properties in the NE gain 20%% value\n");
                    break;
                case Property::kMidwest:
                    printf("All properties in the midwest gain 20%% value\n");
                    break;
                case Property::kSouthwest:
                    printf("All properties in the SW gain 20%% value\n");
                    break;
                case Property::kNorthwest:
                    printf("All properties in the NW gain 20%% value\n");
                    break;
            }
            break;
    }

    if (event != kGentrification) {
        for (int i = 0; i < this->owned_properties.get_size(); i++) {
            this->owned_properties[i]->do_event(event);
        }
        for (int i = 0; i < this->available_properties.get_size(); i++) {
            this->available_properties[i]->do_event(event);
        }
    } else {
        for (int i = 0; i < this->owned_properties.get_size(); i++) {
            this->owned_properties[i]->do_gentrification(location);
        }
        for (int i = 0; i < this->available_properties.get_size(); i++) {
            this->available_properties[i]->do_gentrification(location);
        }
    }
}

void GameManager::update_rent() {
    if (get_yes_no("Would you like to change the rent on a property?")) {
        print_owned();

        int val;
        do {
            val = get_int("Please select the property you would like to update the rent on");
        } while (val < 0 || val >= this->owned_properties.get_size());

        this->owned_properties[val]->update_rent();
    }
}

void GameManager::print_owned() {
    for (int i = 0; i < this->owned_properties.get_size(); i++) {
        printf("Property #%d\n", i+1);
        this->owned_properties[i]->print();
    }
}

void GameManager::print_status() {
    printf("Current Bank Account: %d\n", this->bank_account);
    printf("Number of Properties: %d\n", this->owned_properties.get_size());

    int debt = 0, rent = 0;
    for (int i = 0; i < this->owned_properties.get_size(); i++) {
        rent += this->owned_properties[i]->get_total_rent();
        debt += this->owned_properties[i]->get_mortgage();
    }
    printf("Total Income: %d\n", rent);
    printf("Total Mortgage Payment: %d\n", debt);
}