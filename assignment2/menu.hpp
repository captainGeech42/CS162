#ifndef MENU
#define MENU

#define MENU_DATA "menu.txt"

#include "pizza.hpp"

class Menu {
private:
    int num_pizzas;
    Pizza* pizzas;
public:
    Menu();
    int get_num_pizzas();
    void set_num_pizzas(int);
    Pizza* get_pizzas();
    void set_pizzas(Pizza*);
};

#endif