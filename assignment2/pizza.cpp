#include "pizza.h"

Pizza::Pizza() {
    //TBD
}

std::string Pizza::get_name() {
    return this->name;
}

void Pizza::set_name(std::string name) {
    this->name = name;
}

int Pizza::get_small_cost() {
    return this->small_cost;
}

void Pizza::set_small_cost(int small_cost) {
    this->small_cost = small_cost;
}

int Pizza::get_medium_cost() {
    return this->medium_cost;
}

void Pizza::set_medium_cost(int medium_cost) {
    this->medium_cost = medium_cost;
}

int Pizza::get_large_cost() {
    return this->large_cost;
}

void Pizza::set_large_cost(int large_cost) {
    this->large_cost = large_cost;
}

int Pizza::get_num_ingredients() {
    return this->num_ingredients;
}

void Pizza::set_num_ingredients(int num_ingredients) {
    this->num_ingredients = num_ingredients;
}

std::string* Pizza::get_ingredients() {
    return this->ingredients;
}

void Pizza::set_ingredients(std::string* ingredients) {
    this->ingredients = ingredients;
}