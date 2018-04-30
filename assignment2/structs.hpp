#ifndef STRUCTS
#define STRUCTS

#include <string>

enum Size {
    kSmall = 'S',
    kMedium = 'M',
    kLarge = 'L'
};

enum MainMode {
    kGetOperation = -1,
    kInitialize = 0,
    kCustomer = 1,
    kEmployee = 2,
    kQuit = 3
};

enum CustomerMode {
    kCGetOperation = -1,
    kCViewMenu = 1,
    kCSearchByCost = 2,
    kCSearchByIngredients = 3,
    kCPlaceOrder = 4,
    kCViewHours = 5,
    kCViewAddress = 6,
    kCViewPhone = 7,
    kCLogOut = 8
};

enum EmployeeMode {
    kEGetOperation = -1,
    kEAuthenticate = 0,
    kEChangeHours = 1,
    kEViewOrders = 2,
    kERemoveOrder = 3,
    kEAddItemToMenu = 4,
    kERemoveItemFromMenu = 5,
    kEViewMenu = 6,
    kEViewHours = 7,
    kEViewAddress = 8 ,
    kEViewPhone = 9,
    kELogOut = 10
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