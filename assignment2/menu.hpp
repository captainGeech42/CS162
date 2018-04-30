#ifndef MENU
#define MENU

#define MENU_DATA "menu.txt"

#include "pizza.hpp"
#include "structs.hpp"

#ifdef MAKE
#include "helper.hpp"
#else
#include "O:\cpphelper\helper.hpp"
#endif

class Menu {
private:
    int num_pizzas;
    Pizza* pizzas;
public:
    Menu();
    ~Menu();
    Menu(const Menu&);
    const Menu& operator=(const Menu&);

    int get_num_pizzas() const;
    Pizza* get_pizzas() const;

    Menu search_pizza_by_cost(int upper_bound, Size size);
    Menu search_by_ingredients_to_include(std::string* ingredients, int num_ingredients);
    Menu search_by_ingredients_to_exclude(std::string* ingredients, int num_ingredients);
    void add_to_menu(Pizza pizza_to_add);
    void remove_from_menu(std::string name);
    void print();
    bool contains_pizza(std::string);
    void load_from_file();
    void serialize();
};

#endif