#include "order_manager.hpp"

OrderManager::OrderManager() {
    this->num_orders = 0;
    this->orders = NULL;
    this->next_order_num = 1;
}

OrderManager::~OrderManager() {
    if (this->orders != NULL) delete[] orders;
}

OrderManager::OrderManager(const OrderManager& copy) {
    this->num_orders = copy.num_orders;
    if (this->num_orders > 0) {
        this->orders = new order[this->num_orders];
        for (int i = 0; i < this->num_orders; i++) {
            this->orders[i] = copy.orders[i];
        }
    }
    this->next_order_num = copy.next_order_num;
}

const OrderManager& OrderManager::operator=(const OrderManager& copy) {
    this->num_orders = copy.num_orders;
    if (this->num_orders > 0) {
        this->orders = new order[this->num_orders];
        for (int i = 0; i < this->num_orders; i++) {
            this->orders[i] = copy.orders[i];
        }
    }
    this->next_order_num = copy.next_order_num;
    return *this;
}

void OrderManager::add_order(order* new_order) {
    this->num_orders++;
    order* new_arr = new order[this->num_orders];
    for (int i = 0; i < this->num_orders-1; i++) {
        new_arr[i] = this->orders[i];
    }
    new_order->order_num = this->next_order_num;
    new_arr[this->num_orders-1] = *new_order;
    delete[] this->orders;
    this->orders = new_arr;
    this->next_order_num++;
}

void OrderManager::remove_order(int order_num) {
    for (int i = 0; i < this->num_orders; i++) {
        if (this->orders[i].order_num == order_num) {
            this->orders[i].order_num = -1;
        }
    }
    order* new_arr = new order[this->num_orders-1];
    int counter = 0;
    for (int i = 0; i < this->num_orders; i++) {
        if (this->orders[i].order_num != -1) {
            new_arr[counter] = this->orders[i];
            counter++;
        }
    }
    delete[] this->orders;
    this->orders = new_arr;
    this->num_orders--;
}

bool OrderManager::order_exists(int order_num) {
    if (order_num >= this->next_order_num) return false;
    for (int i = 0; i < this->num_orders; i++) {
        if (this->orders[i].order_num == order_num) return true;
    }
    return false;
}