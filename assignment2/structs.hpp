#ifndef STRUCTS
#define STRUCTS

#include <string>

struct employee {
    std::string id;
    std::string first_name;
    std::string last_name;
    std::string password;
};

struct hours {
    std::string day;
    std::string open_hour;
    std::string close_hour;
};

struct pizza_order {
    std::string name;
    std::string size;
    int quantity;
};

struct order {
    int order_num;
    std::string customer_name;
    std::string credit_card;
    std::string address;
    std::string phone_number;
    std::string num_distinct_pizzas;
    pizza_order* pizzas;
};

#endif