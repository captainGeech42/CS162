#include "pizza.hpp"

Pizza::Pizza() {
    this->name = "";
    this->small_cost = 0;
    this->medium_cost = 0;
    this->large_cost = 0;
    this->num_ingredients = 0;
    this->ingredients = NULL;
}

Pizza::~Pizza() {
    if (this->ingredients != NULL) delete[] this->ingredients;
}

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