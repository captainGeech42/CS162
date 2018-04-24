#ifndef PIZZA
#define PIZZA

#include <string>

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
    std::string get_name();
    void set_name(std::string);
    int get_small_cost();
    void set_small_cost(int);
    int get_medium_cost();
    void set_medium_cost(int);
    int get_large_cost();
    void set_large_cost(int);
    int get_num_ingredients();
    void set_num_ingredients(int);
    std::string* get_ingredients();
    void set_ingredients(std::string*);
};

#endif