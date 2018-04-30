#ifndef STRUCTS
#define STRUCTS

#include <string>

enum Size {
    kSmall = 'S',
    kMedium = 'M',
    kLarge = 'L'
};

struct Employee {
    std::string id;
    std::string first_name;
    std::string last_name;
    std::string password;
};

struct Hours {
    std::string day;
    std::string open_hour;
    std::string close_hour;
};

struct PizzaOrder {
    std::string name;
    Size size;
    int quantity;
};

struct Order {
    int order_num;
    std::string customer_name;
    std::string credit_card;
    std::string address;
    std::string phone_number;
    int num_distinct_pizzas;
    PizzaOrder* pizzas;
};

#endif