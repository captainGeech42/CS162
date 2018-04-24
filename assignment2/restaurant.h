#ifndef RESTAURANT
#define RESTAURANT

#include <string>

#include "menu.h"
#include "pizza.h"
#include "structs.h"

#define NUM_DAYS 7

class Restaurant {
private:
    Menu menu;
    employee* employees;
    int num_employees;
    hours* week;
    std::string name;
    std::string phone;
    std::string address;
public:
    Restaurant();
    Menu get_menu();
    void set_menu(Menu);
    employee* get_employees();
    void set_employees(employee*);
    int get_num_employees();
    void set_num_employees(int);
    hours* get_week();
    void set_week(hours*);
    std::string get_name();
    void set_name(std::string);
    std::string get_phone();
    void set_phone(std::string);
    std::string get_address();
    void set_address(std::string);
};

#endif