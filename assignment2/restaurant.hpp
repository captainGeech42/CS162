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
    Employee* employees;
    int num_employees;
    int days_open;
    Hours* week;
    std::string name;
    std::string phone;
    std::string address;
    OrderManager order_manager;

    void order_from_menu();
    void order_from_menu(Menu);

public:
    Restaurant();
    ~Restaurant();
    const Restaurant& operator=(const Restaurant&);
    Restaurant(const Restaurant&);

    void load_data();
    bool valid_login(std::string, std::string);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void search_menu_by_price();
    void place_order();
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();

    /*** getters and setters ***/
    Menu get_menu() const;
    Employee* get_employees() const;
    int get_num_employees() const;
    Hours* get_week() const;
    std::string get_name() const;
    std::string get_phone() const;
    std::string get_address() const;
};

#endif