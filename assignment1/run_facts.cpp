/*********************************************************************
** Program Filename: run_facts.cpp
** Author: Alexander Nead-Work
** Date: 04/11/2018
** Description: Driver for A1
** Input: command-line arguments
** Output: n/a
*********************************************************************/

#include "facts.h"

/*********************************************************************
** Function: main
** Description: Entry point for the program
** Parameters: int argc, char** argv
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int main(int argc, char** argv) {
    // verify arguments
    if (!is_valid_arguments(argv, argc)) {
        printf("Usage: %s -s [num states] -f [path to data file]\n", argv[0]);
        return 1;
    }

    

    int num_states = get_num_states(argv);
    std::string filepath = get_data_fp(argv);

    // read in data
    std::ifstream input;
    input.open(filepath.c_str());
    while (!input.good()) {
        printf("Invalid filename received.\n");
        printf("Please enter a filename: ");
        std::getline(std::cin, filepath);
        input.close();
        input.open(filepath.c_str());
    }

    // build the arrays
    state* states = create_states(num_states);
    get_state_data(states, num_states, input);

    // get the data
    std::stringstream output;

    /****************** LARGEST STATE ******************/
    output << get_header("Largest State");
    output << "The largest state is " << get_largest_state(states, num_states).name << std::endl;
    output << std::endl;

    /****************** LARGEST COUNTY ******************/
    output << get_header("Largest County");
    output << "The largest county is " << get_largest_county(states, num_states).name << " County" << std::endl;
    output << std::endl;

    /****************** INCOME THRESHOLD ******************/
    output << get_header("Counties with average income above a given threshold");
    threshold_ret income_data = get_counties_income(states, num_states);
    output << "Income Threshold: $" << income_data.threshold << std::endl;
    output << "Counties above the threshold: " << std::endl;
    for (int i = 0; i < income_data.num_counties; i++) {
        output << "\t" << income_data.counties[i].name << " ($" << income_data.counties[i].avg_income << ")" << std::endl;
    }
    delete[] income_data.counties;
    output << std::endl;

    /****************** AVERAGE HOUSEHOLD COST ******************/
    output << get_header("Average household cost for each state");
    avg_house_cost* data = get_average_house_cost(states, num_states);
    for (int i = 0; i < num_states; i++) {
        output << data[i].state << ": $" << data[i].average << std::endl;
    }
    delete[] data;
    output << std::endl;

    /****************** STATE SORT NAME ******************/
    output << get_header("Sorted data by state name");
    sort_states_name(states, num_states);
    output << write_array_data(states, num_states);
    output << std::endl;

    /****************** STATE SORT POPULATION ******************/
    output << get_header("Sorted data by state population");
    sort_states_population(states, num_states);
    output << write_array_data(states, num_states);
    output << std::endl;

    /****************** COUNTY SORT NAME ******************/
    output << get_header("Sorted each state's counties by name");
    sort_all_counties_name(states, num_states);
    output << write_array_data(states, num_states);
    output << std::endl;

    /****************** COUNTY SORT POPULATION ******************/
    output << get_header("Sorted each state's counties by population");
    sort_all_counties_population(states, num_states);
    output << write_array_data(states, num_states);
    output << std::endl;

    // write to ostream
    bool write_to_file = get_yes_no("Would you like to write to file (yes/no)?");
    if (write_to_file) {
        write_str_to_file(output.str());
    } else {
        std::cout << output.str();
    }

    // close/free
    input.close();
    delete_info(&states, num_states);

    return 0;
}