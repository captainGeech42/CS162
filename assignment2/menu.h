#ifndef MENU
#define MENU

#include "pizza.h"

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