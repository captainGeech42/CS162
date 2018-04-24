#include "restaurant.h"

Restaurant::Restaurant() {
    //TBD
}

Menu Restaurant::get_menu() {
    return this->menu;
}

void Restaurant::set_menu(Menu menu) {
    this->menu = menu;
}

employee* Restaurant::get_employees() {
    return this->employees;
}

void Restaurant::set_employees(employee* employees) {
    this->employees = employees;
}

int get_num_employees() {
    return this->num_employees;
}

void set_num_employees(int num_employees) {
    this->num_employees = num_employees;
}

hours* Restaurant::get_week() {
    return this->week;
}

void Restaurant::set_week(hours* week) {
    this->week = week;
}

std::string Restaurant::get_name() {
    return this->name;
}

void Restaurant::set_name(std::string name) {
    this->name = name;
}

std::string Restaurant::get_phone() {
    return this->phone;
}

void Restaurant::set_phone(std::string phone) {
    this->phone = phone;
}

std::string Restaurant::get_address() {
    return this->address;
}

void Restaurant::set_address(std::string address) {
    this->address = address;
}