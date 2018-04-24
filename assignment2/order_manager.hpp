#ifndef ORDER_MANAGER
#define ORDER_MANAGER

#include "structs.hpp"

#define ORDER_DATA "orders.txt"

class OrderManager {
private:
    int num_orders;
    order* orders;
    int next_order_num;
public:
    OrderManager();
    ~OrderManager();

    void add_order(order*);
    void remove_order(int);
    bool order_exists(int);
};

#endif