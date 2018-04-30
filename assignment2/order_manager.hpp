#ifndef ORDER_MANAGER
#define ORDER_MANAGER

#include <iostream>
#include <sstream>

#include "structs.hpp"
#include "pizza.hpp"

#ifdef MAKE
#include "helper.hpp"
#else
#include "O:\cpphelper\helper.hpp"
#endif

#define ORDER_DATA "orders.txt"

class OrderManager {
private:
    int num_orders;
    Order* orders;
    int next_order_num;
    int add_order(Order*);
    void create_order(int, std::string, std::string, std::string, std::string);

public:
    OrderManager();
    ~OrderManager();
    OrderManager(const OrderManager&);
    const OrderManager& operator=(const OrderManager&);

    int create_order(std::string, std::string, std::string, std::string);
    void add_pizza_to_order(int, std::string, int, Size);
    void remove_order(int);
    bool order_exists(int);
    void print();
    void load_from_file();
};

#endif