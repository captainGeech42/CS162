#include "menu.hpp"

Menu::Menu() {
    this->num_pizzas = 0;
    this->pizzas = NULL;
}

Menu::~Menu() {
    if (this->pizzas != NULL) delete[] pizzas;
}

Menu::Menu(const Menu& copy) {
    this->num_pizzas = copy.num_pizzas;
    if (this->num_pizzas > 0) {
        this->pizzas = new Pizza[this->num_pizzas];
        for (int i = 0; i < this->num_pizzas; i++) {
            this->pizzas[i] = copy.pizzas[i];
        }
    }
}

const Menu& Menu::operator=(const Menu& copy) {
    this->num_pizzas = copy.num_pizzas;
    if (this->num_pizzas > 0) {
        this->pizzas = new Pizza[this->num_pizzas];
        for (int i = 0; i < this->num_pizzas; i++) {
            this->pizzas[i] = copy.pizzas[i];
        }
    }
    return *this;
}

int Menu::get_num_pizzas() const { return this->num_pizzas; }
Pizza* Menu::get_pizzas() const { return this->pizzas; }

Menu Menu::search_pizza_by_cost(int upper_bound, std::string size) {
    Menu res;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (strcmpnc(size, "s")) {
            if (this->pizzas[i].get_small_cost() < upper_bound) res.add_to_menu(this->pizzas[i]);
        } else if (strcmpnc(size, "m")) {
            if (this->pizzas[i].get_medium_cost() < upper_bound) res.add_to_menu(this->pizzas[i]);
        } else {
            if (this->pizzas[i].get_large_cost() < upper_bound) res.add_to_menu(this->pizzas[i]);
        }
    }
    return res;
}

Menu Menu::search_by_ingredients_to_include(std::string* ingredients, int num_ingredients) {
    Menu res;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (contains_array(this->pizzas[i].get_num_ingredients(), this->pizzas[i].get_ingredients(), num_ingredients, ingredients)) {
            res.add_to_menu(this->pizzas[i]);
        }
    }
    return res;
}

Menu Menu::search_by_ingredients_to_exclude(std::string* ingredients, int num_ingredients) {
    Menu res;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (contains_array(this->pizzas[i].get_num_ingredients(), this->pizzas[i].get_ingredients(), num_ingredients, ingredients)) {
            res.add_to_menu(this->pizzas[i]);
        }
    }
    return res;
}

void Menu::add_to_menu(Pizza pizza_to_add) {
    this->num_pizzas++;
    Pizza* new_arr = new Pizza[this->num_pizzas];
    for (int i = 0; i < this->num_pizzas-1; i++) {
        new_arr[i] = this->pizzas[i];
    }
    new_arr[this->num_pizzas-1] = pizza_to_add;
    delete[] this->pizzas;
    this->pizzas = new_arr;
}

void Menu::remove_from_menu(std::string name) {
    for (int i = 0; i < this->num_pizzas; i++) {
        if (this->pizzas[i].get_name() == name) {
            this->pizzas[i].set_name("");
        }
    }
    Pizza* new_arr = new Pizza[this->num_pizzas-1];
    int counter = 0;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (this->pizzas[i].get_name() == "") {
            new_arr[counter] = this->pizzas[i];
            counter++;
        }
    }
    delete[] this->pizzas;
    this->pizzas = new_arr;
}
