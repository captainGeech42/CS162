#include "restaurant.hpp"

Restaurant::Restaurant() {
    this->employees = NULL;
    this->num_employees = 0;
    this->days_open = 0;
    this->week = NULL;
    this->name = "";
    this->phone = "";
    this->address = "";
}

Restaurant::~Restaurant() {
    if (this->employees != NULL) delete[] this->employees;
    if (this->week != NULL) delete[] this->week;
}

Restaurant::Restaurant(const Restaurant& copy) {
    this->menu = copy.menu;
    this->num_employees = copy.num_employees;
    if (this->num_employees > 0) {
        this->employees = new Employee[this->num_employees];
        for (int i = 0; i < this->num_employees; i++) {
            this->employees[i] = copy.employees[i];
        }
    }
    this->days_open = copy.days_open;
    if (this->days_open > 0) {
        this->week = new Hours[this->days_open];
        for (int i = 0; i < this->days_open; i++) {
            this->week[i] = copy.week[i];
        }
    }
    this->name = copy.name;
    this->phone = copy.phone;
    this->address = copy.address;
    this->order_manager = copy.order_manager;
}

const Restaurant& Restaurant::operator=(const Restaurant& copy) {
    this->menu = copy.menu;
    this->num_employees = copy.num_employees;
    if (this->num_employees > 0) {
        this->employees = new Employee[this->num_employees];
        for (int i = 0; i < this->num_employees; i++) {
            this->employees[i] = copy.employees[i];
        }
    }
    this->days_open = copy.days_open;
    if (this->days_open > 0) {
        this->week = new Hours[this->days_open];
        for (int i = 0; i < this->days_open; i++) {
            this->week[i] = copy.week[i];
        }
    }
    this->name = copy.name;
    this->phone = copy.phone;
    this->address = copy.address;
    this->order_manager = copy.order_manager;
    return *this;
}

void Restaurant::order_from_menu() { this->order_from_menu(this->menu); }

void Restaurant::order_from_menu(Menu menu) {
    std::string name, credit_card, address, phone_number;

    std::cout << "Please enter your name: ";
    getline(std::cin, name);

    std::cout << "Please enter your credit card number: ";
    getline(std::cin, credit_card);
        
    std::cout << "Please enter your address: ";
    getline(std::cin, address);

    std::cout << "Please enter your phone number: ";
    getline(std::cin, phone_number);

    int order_index = this->order_manager.create_order(name, credit_card, address, phone_number);

    std::string pizza_name;
    bool name_good = true;
    int quantity;
    Size size;
    do {
        do {
            if (!name_good) {
                printf("Invalid pizza name received\n");
                name_good = true;
            }

            std::cout << "Please enter your pizza name: ";
            getline(std::cin, pizza_name);

            name_good = menu.contains_pizza(pizza_name);
        } while (!name_good);

        do {
            quantity = get_int("Please enter your desired quantity: ");
        } while (quantity < 1);

        size = Pizza::get_size();

        this->order_manager.add_pizza_to_order(order_index, pizza_name, quantity, size);
    } while (get_yes_no("Would you like to order another pizza?"));
}

void Restaurant::load_data() {
    // read in restaurant info
    std::ifstream file;
    file.open(RESTAURANT_DATA);
    std::string line;
    int field_counter = 0;
    while (!file.eof()) {
        std::getline(file, line);
        switch (field_counter) {
            case 0:
                this->name = line;
                field_counter++;
                break;
            case 1:
                this->phone = line;
                field_counter++;
                break;
            case 2:
                this->address = line;
                field_counter++;
                break;
            case 3:
                this->days_open = parse_int(line);
                this->week = new Hours[this->days_open];
                for (int i = 0; i < this->days_open; i++) {
                    file >> this->week[i].day;
                    file >> this->week[i].open_hour;
                    file >> this->week[i].close_hour;
                }
                // at this point, we should be at EOF
                break;
        }
    }
    file.close();

    // read in employee data
    file.open(EMPLOYEE_DATA);
    int lines = 0;
    while (!file.eof()) {
        lines++;
        getline(file, line);
    }
    file.close();
    this->num_employees = lines;
    this->employees = new Employee[this->num_employees];
    file.open(EMPLOYEE_DATA);
    for (int i = 0; i < this->num_employees; i++) {
        file >> this->employees[i].id;
        file >> this->employees[i].first_name;
        file >> this->employees[i].last_name;
        file >> this->employees[i].password;
    }
    file.close();

    // read in menu data
    this->menu.load_from_file();

    // read in order data
    this->order_manager.load_from_file();
}

bool Restaurant::valid_login(std::string id, std::string password) {
    for (int i = 0; i < this->num_employees; i++) {
        if (this->employees[i].id == id) {
            if (this->employees[i].password == password) {
                return true;
            }
            return false;
        }
    }
    return false;
}

void Restaurant::view_menu() {
    this->menu.print();
}

void Restaurant::view_hours() {
    std::cout << "Num\tDay\tOpen\tClose" << std::endl;
    for (int i = 0; i < this->days_open; i++) {
        printf("%d\t%s\t%s\t%s\n", i, this->week[i].day.c_str(), this->week[i].open_hour.c_str(), this->week[i].close_hour.c_str());
    }
}

void Restaurant::view_address() {
    std::cout << this->address << std::endl;
}

void Restaurant::view_phone() {
    std::cout << this->phone << std::endl;
}

void Restaurant::search_menu_by_price() {
    int price;
    do {
        price = get_int("Please enter your maximum price");
    } while (price < 0);

    Menu res = this->menu.search_pizza_by_cost(price, Pizza::get_size());

    std::cout << "Here are the pizzas we found:" << std::endl;
    res.print();

    if (get_yes_no("Would you like you to place an order off this search result?")) {
        this->order_from_menu(res);
    }
}

void Restaurant::search_menu_by_ingredients() {
    int op;
    do {
        op = get_int("Would you like to include (1) or exclude (2)? ");
    } while (op < 1 || op > 2);

    std::string* ingredients = new std::string[20];
    int num_ingredients = 0;
    do {
        std::cout << "Please enter the ingredient you would like to search with: ";
        getline(std::cin, ingredients[num_ingredients++]);
    } while (get_yes_no("Would you like to add another ingredient? "));

    Menu res;
    switch (op) {
        case 1: //include
            res = this->menu.search_by_ingredients_to_include(ingredients, num_ingredients);
            break;
        case 2:
            res = this->menu.search_by_ingredients_to_exclude(ingredients, num_ingredients);
            break;
    }

    delete[] ingredients;

    if (res.get_num_pizzas() > 0) {
        std::cout << "Here are the pizzas we found: " << std::endl;
        res.print();

        if (get_yes_no("Would you like to place an order off of this menu? ")) {
            order_from_menu(res);
        }
    } else {
        std::cout << "We didn't find any pizzas that match those criteria" << std::endl;
        return;
    }
}

void Restaurant::place_order() {
    this->order_from_menu();
}

void Restaurant::change_hours() {
    int day;
    do {
        day = get_int("Please enter day #: ");
    } while (day < 0 || day > this->days_open-1);

    std::cout << "Please enter new open hour: " << std::endl;
    getline(std::cin, this->week[day].open_hour);
    
    std::cout << "Please enter new close hour: " << std::endl;
    getline(std::cin, this->week[day].close_hour);
}

void Restaurant::add_to_menu() {
    std::string name;
    int small, medium, large;

    std::cout << "Please enter the pizza name: ";
    getline(std::cin, name);

    do {
        small = get_int("Please enter the small cost: ");
    } while (small < 0);

    do {
        medium = get_int("Please enter the medium cost: ");
    } while (medium < 0);

    do {
        large = get_int("Please enter the large cost: ");
    } while (large < 0);

    Pizza pizza(name, small, medium, large);

    std::string ingredient;
    do {
        std::cout << "Please enter an ingredient: ";
        getline(std::cin, ingredient);

        pizza.add_ingredient(ingredient);
    } while (get_yes_no("Would you like to add another ingredient?"));

    menu.add_to_menu(pizza);
}

void Restaurant::remove_from_menu() {
    std::string pizza;
    do {
        std::cout << "Please enter the name of the pizza you wish to remove: ";
        getline(std::cin, pizza);
    } while (!menu.contains_pizza(pizza));

    menu.remove_from_menu(pizza);
}

void Restaurant::view_orders() {
    this->order_manager.print();
}

void Restaurant::remove_orders() {
    int order_num;
    do {
        order_num = get_int("Please enter the order number you wish to remove: ");
    } while (!this->order_manager.order_exists(order_num));

    this->order_manager.remove_order(order_num);
}

void Restaurant::serialize() {
    std::ofstream file;
    file.open(RESTAURANT_DATA);
    file << this->name << std::endl;
    file << this->phone << std::endl;
    file << this->address << std::endl;
    file << this->num_employees << std::endl;
    for (int i = 0; i < this->num_employees; i++) {
        file << this->week[i].day << " " << this->week[i].open_hour << " " << this->week[i].close_hour << std::endl;
    }
    file.flush();
    file.close();
}

void Restaurant::write_all_to_file() {
    // this->serialize();
    // this->menu.serialize();
    // this->order_manager.serialize();
}

Menu Restaurant::get_menu() const { return this->menu; }

Employee* Restaurant::get_employees() const { return this->employees; }

int Restaurant::get_num_employees() const { return this->num_employees; }

Hours* Restaurant::get_week() const { return this->week; }

std::string Restaurant::get_name() const { return this->name; }

std::string Restaurant::get_phone() const { return this->phone; }

std::string Restaurant::get_address() const { return this->address; }