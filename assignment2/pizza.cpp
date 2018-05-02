#include "pizza.hpp"

/*********************************************************************
** Function: Pizza
** Description: Default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pizza::Pizza() {
    this->name = "";
    this->small_cost = 0;
    this->medium_cost = 0;
    this->large_cost = 0;
    this->num_ingredients = 0;
    this->ingredients = NULL;
}

/*********************************************************************
** Function: Pizza
** Description: Non-default constructor
** Parameters: std::string, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pizza::Pizza(std::string name, int small_cost, int medium_cost, int large_cost) {
    this->name = name;
    this->small_cost = small_cost;
    this->medium_cost = medium_cost;
    this->large_cost = large_cost;
    this->num_ingredients = 0;
    this->ingredients = NULL;
}

/*********************************************************************
** Function: ~Pizza
** Description: Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pizza::~Pizza() {
    if (this->ingredients != NULL) delete[] this->ingredients;
}

/*********************************************************************
** Function: Pizza
** Description: Copy constructor
** Parameters: const Pizza&
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pizza::Pizza(const Pizza& copy) {
    this->name = copy.name;
    this->small_cost = copy.small_cost;
    this->medium_cost = copy.medium_cost;
    this->large_cost = copy.large_cost;
    this->num_ingredients = copy.num_ingredients;
    if (this->num_ingredients > 0) {
        this->ingredients = new std::string[this->num_ingredients];
        for (int i = 0; i < this->num_ingredients; i++) {
            this->ingredients[i] = copy.ingredients[i];
        }
    }
}

/*********************************************************************
** Function: operator=
** Description: Assignment operator overload
** Parameters: const Pizza&
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
const Pizza& Pizza::operator=(const Pizza& copy) {
    this->name = copy.name;
    this->small_cost = copy.small_cost;
    this->medium_cost = copy.medium_cost;
    this->large_cost = copy.large_cost;
    this->num_ingredients = copy.num_ingredients;
    if (this->num_ingredients > 0) {
        this->ingredients = new std::string[this->num_ingredients];
        for (int i = 0; i < this->num_ingredients; i++) {
            this->ingredients[i] = copy.ingredients[i];
        }
    }

    return *this;
}

/*********************************************************************
** Function: get_size
** Description: Gets and parses a size from the user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Size Pizza::get_size() {
    bool good = true;
    Size size;
    std::string foo;

    do {
        if (!good) {
            printf("Invalid size received\n");
            good = true;
        }
        
        std::cout << "Please enter a size (S, M, or L): ";
        getline(std::cin, foo);

        if (strcmpnc("s", foo)) {
            size = kSmall;
        } else if (strcmpnc("m", foo)) {
            size = kMedium;
        } else if (strcmpnc("l", foo)) {
            size = kLarge;
        } else {
            good = false;
        }
    } while (!good);

    return size;
}

/*********************************************************************
** Function: parse_size
** Description: Parses a size from a string
** Parameters: std::string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Size Pizza::parse_size(std::string size) {
    if (strcmpnc(size, "s")) return kSmall;
    else if (strcmpnc(size, "m")) return kMedium;
    else if (strcmpnc(size, "l")) return kLarge;

    printf("invalid size when parsing from string \"%s\"\n", size.c_str());
    exit(1);
}

void Pizza::add_ingredient(std::string ingredient) {
    this->num_ingredients++;
    std::string* new_arr = new std::string[this->num_ingredients];
    for (int i = 0; i < this->num_ingredients-1; i++) {
        new_arr[i] = this->ingredients[i];
    }
    new_arr[this->num_ingredients-1] = ingredient;
    if (this->ingredients != NULL) delete[] this->ingredients;
    this->ingredients = new_arr;
}

std::string Pizza::get_name() const { return this->name; }

void Pizza::set_name(std::string name) { this->name = name; }

int Pizza::get_small_cost() const { return this->small_cost; }

void Pizza::set_small_cost(int small_cost) { this->small_cost = small_cost; }

int Pizza::get_medium_cost() const { return this->medium_cost; }

void Pizza::set_medium_cost(int medium_cost) { this->medium_cost = medium_cost; }

int Pizza::get_large_cost() const { return this->large_cost; }

void Pizza::set_large_cost(int large_cost) { this->large_cost = large_cost; }

int Pizza::get_num_ingredients() const { return this->num_ingredients; }

std::string* Pizza::get_ingredients() const { return this->ingredients; }