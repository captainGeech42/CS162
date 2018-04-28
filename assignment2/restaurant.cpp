#include "restaurant.hpp"

Restaurant::Restaurant() {
    this->employees = NULL;
    this->num_employees = 0;
    this->days_open = 0;
    this->week = NULL;
    this->name = "";
    this->phone = "";
    this->address = "";
}

Restaurant::~Restaurant() {
    if (this->employees != NULL) delete[] this->employees;
    if (this->employees != NULL) delete[] this->week;
}

Restaurant::Restaurant(const Restaurant& copy) {
    this->menu = copy.menu;
    this->num_employees = copy.num_employees;
    if (this->num_employees > 0) {
        this->employees = new employee[this->num_employees];
        for (int i = 0; i < this->num_employees; i++) {
            this->employees[i] = copy.employees[i];
        }
    }
    this->days_open = copy.days_open;
    if (this->days_open > 0) {
        this->week = new hours[this->days_open];
        for (int i = 0; i < this->days_open; i++) {
            this->week[i] = copy.week[i];
        }
    }
    this->name = copy.name;
    this->phone = copy.phone;
    this->address = copy.address;
    this->order_manager = copy.order_manager;
}

const Restaurant& Restaurant::operator=(const Restaurant& copy) {
    this->menu = copy.menu;
    this->num_employees = copy.num_employees;
    if (this->num_employees > 0) {
        this->employees = new employee[this->num_employees];
        for (int i = 0; i < this->num_employees; i++) {
            this->employees[i] = copy.employees[i];
        }
    }
    this->days_open = copy.days_open;
    if (this->days_open > 0) {
        this->week = new hours[this->days_open];
        for (int i = 0; i < this->days_open; i++) {
            this->week[i] = copy.week[i];
        }
    }
    this->name = copy.name;
    this->phone = copy.phone;
    this->address = copy.address;
    this->order_manager = copy.order_manager;
    return *this;
}

void Restaurant::load_data() {
    // read in restaurant info
    std::ifstream file;
    file.open(RESTAURANT_DATA);
    std::string line;
    int field_counter = 0;
    while (!file.eof()) {
        std::getline(file, line);
        switch (field_counter) {
            case 0:
                this->name = line;
                field_counter++;
                break;
            case 1:
                this->phone = line;
                field_counter++;
                break;
            case 2:
                this->address = line;
                field_counter++;
                break;
            case 3:
                this->days_open = parse_int(line);
                this->week = new hours[this->days_open];
                for (int i = 0; i < this->days_open; i++) {
                    file >> this->week[i].day;
                    file >> this->week[i].open_hour;
                    file >> this->week[i].close_hour;
                }
                // at this point, we should be at EOF
                break;
        }
    }

    // read in
}
/*
bool Restaurant::login(std::string, std::string);
void Restaurant::view_menu();
void Restaurant::view_hours();
void Restaurant::view_address();
void Restaurant::view_phone();
void Restaurant::search_menu_by_price();
void Restaurant::place_order(Pizza* selection);
void Restaurant::change_hours();
void Restaurant::add_to_menu();
void Restaurant::remove_from_menu();
void Restaurant::view_orders();
void Restaurant::remove_orders();
*/

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

int Restaurant::get_num_employees() {
    return this->num_employees;
}

void Restaurant::set_num_employees(int num_employees) {
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