#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "pizza.hpp"
#include "restaurant.hpp"
#include "menu.hpp"
#include "order_manager.hpp"
#include "structs.hpp"

int main() {
    MainMode mMode = kInitialize;
    CustomerMode cMode = kCGetOperation;
    EmployeeMode eMode = kEAuthenticate;

    Restaurant restaurant;

    bool continue_mode;
    int op;
    std::string id, password;

    while (true) {
        switch (mMode) {
            case kGetOperation:
                printf("Welcome to %s!\n", restaurant.get_name().c_str());
                do {
                    op = get_int("Are you a customer (1) or an employee (2) (press 3 to quit)? ");
                } while (op < 1 || op > 3);
                mMode = static_cast<MainMode>(op);
                continue_mode = true;
                break;
            case kInitialize:
                restaurant.load_data();
                mMode = kGetOperation;
                break;
            case kCustomer:
                while (continue_mode) {
                    switch (cMode) {
                        case kCGetOperation:
                            std::cout << "What would you like to do?" << std::endl;
                            std::cout << "\t1. View Menu" << std::endl;
                            std::cout << "\t2. Search by Cost" << std::endl;
                            std::cout << "\t3. Search by Ingredients" << std::endl;
                            std::cout << "\t4. Place Order" << std::endl;
                            std::cout << "\t5. View Hours" << std::endl;
                            std::cout << "\t6. View Address" << std::endl;
                            std::cout << "\t7. View Phone" << std::endl;
                            std::cout << "\t8. Log Out" << std::endl;

                            do {
                                op = get_int("Selection: ");
                            } while (op < 1 || op > 8);

                            cMode = static_cast<CustomerMode>(op);
                            break;
                        case kCViewMenu:
                            restaurant.view_menu();
                            cMode = kCGetOperation;
                            break;
                        case kCSearchByCost:
                            restaurant.search_menu_by_price();
                            cMode = kCGetOperation;
                            break;
                        case kCSearchByIngredients:
                            restaurant.search_menu_by_ingredients();
                            cMode = kCGetOperation;
                            break;
                        case kCPlaceOrder:
                            restaurant.place_order();
                            cMode = kCGetOperation;
                            break;
                        case kCViewHours:
                            restaurant.view_hours();
                            cMode = kCGetOperation;
                            break;
                        case kCViewAddress:
                            restaurant.view_address();
                            cMode = kCGetOperation;
                            break;
                        case kCViewPhone:
                            restaurant.view_phone();
                            cMode = kCGetOperation;
                            break;
                        case kCLogOut:
                            restaurant.write_all_to_file();
                            continue_mode = false;
                            cMode = kCGetOperation;
                            break;
                    }
                }
                mMode = kGetOperation;
                break;
            case kEmployee:
                while (continue_mode) {
                    switch (eMode) {
                        case kEGetOperation:
                            std::cout << "What would you like to do?" << std::endl;
                            std::cout << "\t1. Change Hours" << std::endl;
                            std::cout << "\t2. View Orders" << std::endl;
                            std::cout << "\t3. Remove Order" << std::endl;
                            std::cout << "\t4. Add Item to Menu" << std::endl;
                            std::cout << "\t5. Remove Item from Menu" << std::endl;
                            std::cout << "\t6. View Menu" << std::endl;
                            std::cout << "\t7. View Hours" << std::endl;
                            std::cout << "\t8. View Address" << std::endl;
                            std::cout << "\t9. View Phone" << std::endl;
                            std::cout << "\t10. Log Out" << std::endl;

                            do {
                                op = get_int("Selection: ");
                            } while (op < 1 || op > 10);

                            eMode = static_cast<EmployeeMode>(op);
                            break;
                        case kEAuthenticate:
                            do {
                                std::cout << "Please enter your ID: ";
                                getline(std::cin, id);

                                std::cout << "Please enter your password: ";
                                getline(std::cin, password);
                            } while (!restaurant.valid_login(id, password));

                            eMode = kEGetOperation;
                            break;
                        case kEChangeHours:
                            restaurant.change_hours();
                            eMode = kEGetOperation;
                            break;
                        case kEViewOrders:
                            restaurant.view_orders();
                            eMode = kEGetOperation;
                            break;
                        case kERemoveOrder:
                            restaurant.remove_orders();
                            eMode = kEGetOperation;
                            break;
                        case kEAddItemToMenu:
                            restaurant.add_to_menu();
                            eMode = kEGetOperation;
                            break;
                        case kERemoveItemFromMenu:
                            restaurant.remove_from_menu();
                            eMode = kEGetOperation;
                            break;
                        case kEViewMenu:
                            restaurant.view_menu();
                            eMode = kEGetOperation;
                            break;
                        case kEViewHours:
                            restaurant.view_hours();
                            eMode = kEGetOperation;
                            break;
                        case kEViewAddress:
                            restaurant.view_address();
                            eMode = kEGetOperation;
                            break;
                        case kEViewPhone:
                            restaurant.view_phone();
                            eMode = kEGetOperation;
                            break;
                        case kELogOut:
                            restaurant.write_all_to_file();
                            continue_mode = false;
                            eMode = kEAuthenticate;
                            break;
                    }
                }
                mMode = kGetOperation;
                break;
            case kQuit:
                return 0;
        }
    }
}