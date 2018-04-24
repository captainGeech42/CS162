#include <stdio.h>
#include <string>

#include "pizza.h"
#include "restaurant.h"
#include "menu.h"
#include "structs.h"

int main() {
    Pizza pizza;
    pizza.set_name("Meat Lovers");
    pizza.set_small_cost(8);
    pizza.set_medium_cost(pizza.get_small_cost()+2);
    pizza.set_large_cost(pizza.get_medium_cost()+2);
    int num_ingredients = 4;
    std::string* ingredients = new std::string[num_ingredients];
    ingredients[0] = "Cheese";
    ingredients[1] = "Sausage";
    ingredients[2] = "Pepperonni";
    ingredients[3] = "Canadian Bacon";
    pizza.set_num_ingredients(num_ingredients);
    pizza.set_ingredients(ingredients);

    printf("[*] Pizza has been made\n");
    printf("Pizza name: %s\n", pizza.get_name().c_str());
    printf("Pizza costs (S, M, L): %d, %d, %d\n", pizza.get_small_cost(), pizza.get_medium_cost(), pizza.get_large_cost());
    printf("Ingredients: %d\n", pizza.get_num_ingredients());
    printf("Ingredient @ 0: %s\n", pizza.get_ingredients()[0].c_str());

    Menu menu;
    menu.set_num_pizzas(1);
    menu.set_pizzas(&pizza);

    printf("[*] Menu has been made\n");
    printf("Pizzas: %d\n", menu.get_num_pizzas());
    printf("Pizza @ 0: %s\n", menu.get_pizzas()->get_name().c_str());

    Restaurant restaurant;
    restaurant.set_menu(menu);
    employee emp;
    emp.id = "1";
    emp.first_name = "John";
    emp.last_name = "Doe";
    emp.password = "myvoiceismypassport";
    restaurant.set_employees(&emp);
    hours* week = new hours[7];
    for (int i = 0; i < 7; i++) {
        switch (i) {
            case 0:
            week[i].day = "M";
            break;
            case 1:
            week[i].day = "T";
            break;
            case 2:
            week[i].day = "W";
            break;
            case 3:
            week[i].day = "R";
            break;
            case 4:
            week[i].day = "F";
            break;
            case 5:
            week[i].day = "S";
            break;
            case 6:
            week[i].day = "U";
            break;
        }
        week[i].open_hour = "10:00";
        week[i].close_hour = "23:00";
    }
    restaurant.set_week(week);
    restaurant.set_name("Test Pizza Shop");
    restaurant.set_phone("555-555-1234");
    restaurant.set_address("1 Pizza Lane");

    printf("[*] Restaurant has been made\n");
    printf("Employee @ 0: %s\n", restaurant.get_employees()->first_name.c_str());
    printf("Opening hour @ 0: %s\n", restaurant.get_week()->open_hour.c_str());
    printf("Name: %s\n", restaurant.get_name().c_str());
    printf("Phone #: %s\n", restaurant.get_phone().c_str());
    printf("Address: %s\n", restaurant.get_address().c_str());

    delete[] ingredients;
    delete[] week;
    printf("[*] Memory has been freed\n");
}