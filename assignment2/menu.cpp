#include "menu.h"

Menu::Menu() {
    //TBD
}

int Menu::get_num_pizzas() {
    return this->num_pizzas;
}

void Menu::set_num_pizzas(int num_pizzas) {
    this->num_pizzas = num_pizzas;
}

Pizza* Menu::get_pizzas() {
    return this->pizzas;
}

void Menu::set_pizzas(Pizza* pizzas) {
    this->pizzas = pizzas;
}