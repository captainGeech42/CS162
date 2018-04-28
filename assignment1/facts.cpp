/*********************************************************************
** Program Filename: facts.cpp
** Author: Alexander Nead-Work
** Date: 04/11/2018
** Description: Function implementations for A1
** Input: n/a
** Output: n/a
*********************************************************************/

#include "facts.h"

/*********************************************************************
** Function: is_arguments_valid
** Description: Checks if command line arguments are valid
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool is_valid_arguments(char** argv, int argc) {
    // argc == 5
    if (argc != 5) return false;

    // argv has -s and -f
    if (!(strcmp("-s", argv[1]) == 0 && strcmp("-f", argv[3]) == 0) && !(strcmp("-f", argv[1]) == 0 && strcmp("-s", argv[3]) == 0)) return false;

    // -s value is integer
    std::string s;
    if (strcmp("-s", argv[1]) == 0) {
        while (!is_int(std::string(argv[2])) && (s.length() == 0 || !is_int(s))) {
            printf("Invalid integer received for -s\n");
            printf("Please enter a valid integer: ");
            getline(std::cin, s);
        }
    } else {
        while (!is_int(std::string(argv[4])) && (s.length() == 0 || !is_int(s))) {
            printf("Invalid integer received for -s\n");
            printf("Please enter a valid integer: ");
            getline(std::cin, s);
        }
    }

    return true;
}

/*********************************************************************
** Function: get_num_states
** Description: Returns the number of states
** Parameters: char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int get_num_states(char** argv) {
    if (strcmp("-s", argv[1]) == 0) {
        return parse_int(std::string(argv[2]));
    } else {
        return parse_int(std::string(argv[4]));
    }
}

/*********************************************************************
** Function: get_data_fp
** Description: Returns the filepath for the data file
** Parameters: char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
std::string get_data_fp(char** argv) {
    if (strcmp("-f", argv[1]) == 0) {
        return std::string(argv[2]);
    } else {
        return std::string(argv[4]);
    }
}

/*********************************************************************
** Function: create_states
** Description: Makes an array of states
** Parameters: int length
** Pre-Conditions: length is a positive number
** Post-Conditions: none
*********************************************************************/
state* create_states(int length) {
    state* array = new state[length];
    return array;
}

/*********************************************************************
** Function: get_state_data
** Description: Puts data from the file into the state array
** Parameters: state* states, int length, std::ifstream& file
** Pre-Conditions: states has been initalized with $length elements, file is good
** Post-Conditions: none
*********************************************************************/
void get_state_data(state* states, int length, std::ifstream& file) {
    for (int i = 0; i < length; i++) {
        file >> states[i].name;
        file >> states[i].population;
        file >> states[i].counties;

        states[i].c = create_counties(states[i].counties);
        get_county_data(states[i].c, states[i].counties, file);
    }
}

/*********************************************************************
** Function: create_counties
** Description: Makes an array of counties
** Parameters: int length
** Pre-Conditions: length is a positive number
** Post-Conditions: none
*********************************************************************/
county* create_counties(int length) {
    county* array = new county[length];
    return array;
}

/*********************************************************************
** Function: get_county_data
** Description: Puts data from the file into the county array
** Parameters: county* counties, int length, std::ifstream& file
** Pre-Conditions: counties has been initalized with $length elements, file is good
** Post-Conditions: none
*********************************************************************/
void get_county_data(county* counties, int length, std::ifstream& file) {
    for (int i = 0; i < length; i++) {
        file >> counties[i].name;
        file >> counties[i].population;
        file >> counties[i].avg_income;
        file >> counties[i].avg_house;

        file >> counties[i].cities;
        counties[i].city = new std::string[counties[i].cities];
        for (int j = 0; j < counties[i].cities; j++) {
            file >> counties[i].city[j];
        }
    }
}

/*********************************************************************
** Function: delete_info
** Description: Frees the memory for the state & county arrays
** Parameters: state** states, int length
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void delete_info(state** states, int length) {
    if (states == NULL) return;

    for (int i = 0; i < length; i++) {
        if ((*states)[i].c != NULL) {
            // delete city array for each county
            for (int j = 0; j < (*states)[i].counties; j++) {
                if ((*states)[i].c[j].city != NULL) {
                    delete[] (*states)[i].c[j].city;
                    (*states)[i].c[j].city = NULL;
                }
            }

            // delete county array for each state
            delete[] (*states)[i].c;
            (*states)[i].c = NULL;
        }
    }

    // delete state array
    delete[] (*states);
    states = NULL;
}

/*********************************************************************
** Function: print_data
** Description: Writes all of the data to the screen
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
std::string write_array_data(state* states, int length) {
    std::stringstream ss;
    for (int i = 0; i < length; i++) {
        // print state info
        ss << "====== " << states[i].name << " ======" << std::endl;
        ss << "Population: " << states[i].population << std::endl;

        // print county info
        ss << states[i].counties << " counties" << std::endl;
        for (int j = 0; j < states[i].counties; j++) {
            ss << "\t" << states[i].c[j].name << std::endl;
            ss << "\tPopulation: " << states[i].c[j].population << std::endl;
            ss << "\tAverage Income: $" << states[i].c[j].avg_income << std::endl;
            ss << "\tAverage House Cost: $" << states[i].c[j].avg_house << std::endl;

            // print city info
            ss << "\t" << states[i].c[j].cities << " cities" << std::endl;
            for (int k = 0; k < states[i].c[j].cities; k++) {
                ss << "\t\t" << states[i].c[j].city[k] << std::endl;
            }
            ss << std::endl;
        }
        ss << std::endl;
    }

    return ss.str();
}

/*********************************************************************
** Function: get_largest_state
** Description: Returns the largest state by population
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
state get_largest_state(state* states, int length) {
    state largest;
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            largest = states[i];
        } else {
            if (states[i].population > largest.population) {
                largest = states[i];
            }
        }
    }
    return largest;
}

/*********************************************************************
** Function: get_largest_county
** Description: Returns the largest county by population
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
county get_largest_county(state* states, int length) {
    county largest;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < states[i].counties; j++) {
            if (i == 0 && j == 0) {
                largest = states[i].c[j];
            } else {
                if (states[i].c[j].population > largest.population) largest = states[i].c[j];
            }
        }
    }
    return largest;
}

/*********************************************************************
** Function: get_counties_income
** Description: Returns all counties with income above a certain amount
** Parameters: state* states, int length, county* counties
** Pre-Conditions: states has data, counties is a null pointer
** Post-Conditions: $counties will have all counties with income above the threshold (length is the retval)
*********************************************************************/
threshold_ret get_counties_income(state* states, int length) {
    threshold_ret ret;
    ret.threshold = get_float("Please enter an income threshold: ");
    ret.num_counties = get_num_counties(states, length, ret.threshold);
    ret.counties = new county[ret.num_counties];

    int counter = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < states[i].counties; j++) {
            if (states[i].c[j].avg_income >= ret.threshold) {
                ret.counties[counter] = states[i].c[j];
                counter++;
            }
        }
    }

    return ret;
}

/*********************************************************************
** Function: get_num_counties
** Description: Gets the number of counties with income above a threshold
** Parameters: state* states, int length, float threshold
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
int get_num_counties(state* states, int length, float threshold) {
    int counties = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < states[i].counties; j++) {
            if (states[i].c[j].avg_income >= threshold) counties++;
        }
    }
    return counties;
}

/*********************************************************************
** Function: get_average_house_cost
** Description: Gets the average house cost for each state
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
avg_house_cost* get_average_house_cost(state* states, int length) {
    avg_house_cost* avg_house_costs = new avg_house_cost[length];
    float sum;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < states[i].counties; j++) {
            sum += states[i].c[j].avg_house;
        }

        avg_house_costs[i].state = states[i].name;
        avg_house_costs[i].average = (float) sum / states[i].counties;
        sum = 0;
    }

    return avg_house_costs;
}

/*********************************************************************
** Function: swap_states
** Description: Swaps two states
** Parameters: state* states, int src, int dest
** Pre-Conditions: states has data
** Post-Conditions: src and dest items will be swapped
*********************************************************************/
void swap_states(state* states, int src, int dest) {
    state temp = states[src];
    states[src] = states[dest];
    states[dest] = temp;
}

/*********************************************************************
** Function: swap_counties
** Description: Swaps two counties
** Parameters: county* counties, int src, int dest
** Pre-Conditions: counties has data
** Post-Conditions: src and dest items will be swapped
*********************************************************************/
void swap_counties(county* counties, int src, int dest) {
    county temp = counties[src];
    counties[src] = counties[dest];
    counties[dest] = temp;
}

/*********************************************************************
** Function: is_sorted_states_name
** Description: Checks if the states array is sorted by name
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
bool is_sorted_states_name(state* states, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (states[i].name > states[i + 1].name) return false;
    }
    return true;
}

/*********************************************************************
** Function: sort_states_name
** Description: Sorts the states array by name
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: states will be sorted
*********************************************************************/
void sort_states_name(state* states, int length) {
    while (!is_sorted_states_name(states, length)) {
        for (int i = 0; i < length - 1; i++) {
            if (states[i].name > states[i + 1].name) swap_states(states, i, i + 1);
        }
    }
}

/*********************************************************************
** Function: is_sorted_states_population
** Description: Checks if the states array is sorted by population
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
bool is_sorted_states_population(state* states, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (states[i].population > states[i + 1].population) return false;
    }
    return true;
}

/*********************************************************************
** Function: sort_states_population
** Description: Sorts the states array by population
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: states will be sorted
*********************************************************************/
void sort_states_population(state* states, int length) {
    while (!is_sorted_states_population(states, length)) {
        for (int i = 0; i < length - 1; i++) {
            if (states[i].population > states[i + 1].population) swap_states(states, i, i + 1);
        }
    }
}

/*********************************************************************
** Function: is_sorted_counties_name
** Description: Checks if the counties array is sorted by name
** Parameters: county* counties, int length
** Pre-Conditions: counties has data
** Post-Conditions: none
*********************************************************************/
bool is_sorted_counties_name(county* counties, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (counties[i].name > counties[i + 1].name) return false;
    }
    return true;
}

/*********************************************************************
** Function: sort_counties_name
** Description: Sorts the counties array by name
** Parameters: county* counties, int length
** Pre-Conditions: counties has data
** Post-Conditions: counties will be sorted
*********************************************************************/
void sort_counties_name(county* counties, int length) {
    while (!is_sorted_counties_name(counties, length)) {
        for (int i = 0; i < length - 1; i++) {
            if (counties[i].name > counties[i + 1].name) swap_counties(counties, i, i + 1);
        }
    }
}

/*********************************************************************
** Function: is_sorted_counties_population
** Description: Checks if the counties array is sorted by population
** Parameters: county* counties, int length
** Pre-Conditions: counties has data
** Post-Conditions: none
*********************************************************************/
bool is_sorted_counties_population(county* counties, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (counties[i].population > counties[i + 1].population) return false;
    }
    return true;
}

/*********************************************************************
** Function: sort_counties_population
** Description: Sorts the counties array by population
** Parameters: county* counties, int length
** Pre-Conditions: counties has data
** Post-Conditions: counties will be sorted
*********************************************************************/
void sort_counties_population(county* counties, int length) {
    while (!is_sorted_counties_population(counties, length)) {
        for (int i = 0; i < length - 1; i++) {
            if (counties[i].population > counties[i + 1].population) swap_counties(counties, i, i + 1);
        }
    }
}

/*********************************************************************
** Function: sort_all_counties_name
** Description: Sorts all counties by name
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
void sort_all_counties_name(state* states, int length) {
    for (int i = 0; i < length; i++) {
        sort_counties_name(states[i].c, states[i].counties);
    }
}

/*********************************************************************
** Function: sort_all_counties_population
** Description: Sorts all counties by population
** Parameters: state* states, int length
** Pre-Conditions: states has data
** Post-Conditions: none
*********************************************************************/
void sort_all_counties_population(state* states, int length) {
    for (int i = 0; i < length; i++) {
        sort_counties_population(states[i].c, states[i].counties);
    }
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/