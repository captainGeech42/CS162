#ifndef RESTAURANT
#define RESTAURANT

#include <string>
#include <fstream>
#include <stdio.h>

#include "menu.hpp"
#include "pizza.hpp"
#include "order_manager.hpp"
#include "structs.hpp"

#ifdef MAKE
#include "helper.hpp"
#else
#include "O:\cpphelper\helper.hpp"
#endif

#define EMPLOYEE_DATA "employee.txt"
#define RESTAURANT_DATA "restaurant_info.txt"

class Restaurant {
private:
    Menu menu;
    employee* employees;
    int num_employees;
    int days_open;
    hours* week;
    std::string name;
    std::string phone;
    std::string address;
    OrderManager order_manager;

public:
    Restaurant();
    ~Restaurant();
    const Restaurant& operator=(const Restaurant&);
    Restaurant(const Restaurant&);

    void load_data();
    bool login(std::string, std::string);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void search_menu_by_price();
    void place_order(Pizza* selection);
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();

    /*** getters and setters ***/
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