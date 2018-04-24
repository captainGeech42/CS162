/*********************************************************************
** Program Filename: facts.h
** Author: Alexander Nead-Work
** Date: 04/11/2018
** Description: Header file for A1
** Input: n/a
** Output: n/a
*********************************************************************/

#ifndef FACTS

/**************************** definitions ****************************/
#define FACTS

/**************************** includes ****************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include "helper.hpp"

/**************************** enums ****************************/

/**************************** structs ****************************/
struct county {
    std::string name;
    std::string *city;
    int cities;
    int population;
    float avg_income;
    float avg_house;
};

struct state {
    std::string name;
    struct county *c;
    int counties;
    int population;
};

struct avg_house_cost {
    std::string state;
    float average;
};

struct threshold_ret {
    float threshold;
    int num_counties;
    county* counties;
};

/**************************** functions ****************************/
bool is_valid_arguments(char*[], int);
int get_num_states(char**);
std::string get_data_fp(char**);
state* create_states(int);
void get_state_data(state*, int, std::ifstream&);
county* create_counties(int);
void get_county_data(county*, int, std::ifstream&);
void delete_info(state**, int);
std::string write_array_data(state*, int);
state get_largest_state(state*, int);
county get_largest_county(state*, int);
threshold_ret get_counties_income(state*, int);
int get_num_counties(state*, int, float);
avg_house_cost* get_average_house_cost(state*, int);
void swap_states(state*, int, int);
void swap_counties(county*, int, int);
bool is_sorted_states_name(state*, int);
void sort_states_name(state*, int);
bool is_sorted_states_population(state*, int);
void sort_states_population(state*, int);
bool is_sorted_counties_name(county*, int);
void sort_counties_name(state*, int);
bool is_sorted_counties_population(county*, int);
void sort_counties_population(county*, int);
void sort_all_counties_name(state*, int);
void sort_all_counties_population(state*, int);

#endif