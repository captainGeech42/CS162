#include "menu.hpp"

Menu::Menu() {
    this->num_pizzas = 0;
    this->pizzas = NULL;
}

Menu::~Menu() {
    if (this->pizzas != NULL) delete[] pizzas;
}

Menu::Menu(const Menu& copy) {
    this->num_pizzas = copy.num_pizzas;
    if (this->num_pizzas > 0) {
        this->pizzas = new Pizza[this->num_pizzas];
        for (int i = 0; i < this->num_pizzas; i++) {
            this->pizzas[i] = copy.pizzas[i];
        }
    }
}

const Menu& Menu::operator=(const Menu& copy) {
    this->num_pizzas = copy.num_pizzas;
    if (this->num_pizzas > 0) {
        this->pizzas = new Pizza[this->num_pizzas];
        for (int i = 0; i < this->num_pizzas; i++) {
            this->pizzas[i] = copy.pizzas[i];
        }
    }
    return *this;
}

int Menu::get_num_pizzas() const { return this->num_pizzas; }
Pizza* Menu::get_pizzas() const { return this->pizzas; }

Menu Menu::search_pizza_by_cost(int upper_bound, Size size) {
    Menu res;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (size == kSmall) {
            if (this->pizzas[i].get_small_cost() < upper_bound) res.add_to_menu(this->pizzas[i]);
        } else if (size == kMedium) {
            if (this->pizzas[i].get_medium_cost() < upper_bound) res.add_to_menu(this->pizzas[i]);
        } else {
            if (this->pizzas[i].get_large_cost() < upper_bound) res.add_to_menu(this->pizzas[i]);
        }
    }
    return res;
}

Menu Menu::search_by_ingredients_to_include(std::string* ingredients, int num_ingredients) {
    Menu res;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (contains_array(this->pizzas[i].get_num_ingredients(), this->pizzas[i].get_ingredients(), num_ingredients, ingredients)) {
            res.add_to_menu(this->pizzas[i]);
        }
    }
    return res;
}

Menu Menu::search_by_ingredients_to_exclude(std::string* ingredients, int num_ingredients) {
    Menu res;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (contains_array(this->pizzas[i].get_num_ingredients(), this->pizzas[i].get_ingredients(), num_ingredients, ingredients)) {
            res.add_to_menu(this->pizzas[i]);
        }
    }
    return res;
}

void Menu::add_to_menu(Pizza pizza_to_add) {
    this->num_pizzas++;
    Pizza* new_arr = new Pizza[this->num_pizzas];
    for (int i = 0; i < this->num_pizzas-1; i++) {
        new_arr[i] = this->pizzas[i];
    }
    new_arr[this->num_pizzas-1] = pizza_to_add;
    if (this->pizzas != NULL) delete[] this->pizzas;
    this->pizzas = new_arr;
}

void Menu::remove_from_menu(std::string name) {
    for (int i = 0; i < this->num_pizzas; i++) {
        if (this->pizzas[i].get_name() == name) {
            this->pizzas[i].set_name("");
        }
    }
    Pizza* new_arr = new Pizza[this->num_pizzas-1];
    int counter = 0;
    for (int i = 0; i < this->num_pizzas; i++) {
        if (this->pizzas[i].get_name() == "") {
            new_arr[counter] = this->pizzas[i];
            counter++;
        }
    }
    if (this->pizzas != NULL) delete[] this->pizzas;
    this->pizzas = new_arr;
}

void Menu::print() {
    std::cout << "Name\tS/M/L\tIngredients" << std::endl;
    std::cout << std::string('-', 25);
    for (int i = 0; i < this->num_pizzas; i++) {
        printf("%s\t$%d/$%d/$%d\t", this->pizzas[i].get_name().c_str(), this->pizzas[i].get_small_cost(), this->pizzas[i].get_medium_cost(), this->pizzas[i].get_large_cost());
        for (int j = 0; j < this->pizzas[i].get_num_ingredients(); j++) {
            std::cout << this->pizzas[i].get_ingredients()[j];
            if (j != this->pizzas[i].get_num_ingredients()-1) {
                std::cout << ", ";
            } else {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

bool Menu::contains_pizza(std::string name) {
    for (int i = 0; i < this->num_pizzas; i++) {
        if (this->pizzas[i].get_name() == name) return true;
    }
    return false;
}

void Menu::load_from_file() {
    if (!is_file_empty(MENU_DATA)) {
        std::ifstream file;
        file.open(MENU_DATA);

        std::string line;
        int lines = 0;
        while (!file.eof()) {
            lines++;
            getline(file, line);
        }

        file.close();
        file.open(MENU_DATA);

        std::string name, temp;
        int small, medium, large, num_ingredients;
        for (int i = 0; i < lines; i++) {
            file >> name;
            file >> small;
            file >> medium;
            file >> large;
            file >> num_ingredients;

            Pizza pizza(name, small, medium, large);

            for (int j = 0; j < num_ingredients; j++) {
                file >> temp;
                pizza.add_ingredient(temp);
            }

            this->add_to_menu(pizza);
        }

        file.close();
    }
}