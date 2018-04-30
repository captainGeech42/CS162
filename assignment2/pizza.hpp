#ifndef PIZZA
#define PIZZA

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "structs.hpp"

#ifdef MAKE
#include "helper.hpp"
#else
#include "O:\cpphelper\helper.hpp"
#endif


class Pizza {
private:
    std::string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    std::string* ingredients;

public:
    Pizza();
    Pizza(std::string, int, int, int);
    ~Pizza();
    Pizza(const Pizza&);
    const Pizza& operator=(const Pizza&);

    static Size get_size();
    static Size parse_size(std::string);
    void add_ingredient(std::string);

    std::string get_name() const;
    void set_name(std::string);
    int get_small_cost() const;
    void set_small_cost(int);
    int get_medium_cost() const;
    void set_medium_cost(int);
    int get_large_cost() const;
    void set_large_cost(int);
    int get_num_ingredients() const;
    std::string* get_ingredients() const;
};

#endif