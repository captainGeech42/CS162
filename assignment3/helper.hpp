/*********************************************************************
** Program Filename: helper.hpp
** Author: Alexander Nead-Work
** Date: 01/31/2018
** Description: Header file for A3
** Input: n/a
** Output: n/a
*********************************************************************/

#ifndef HELPER
#define HELPER

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

bool check_range(int, int, int);
bool is_int(std::string);
bool is_float(std::string);
bool is_capital(char);
bool is_even(int);
bool is_odd(int);
int equality_test(int, int);
bool float_is_equal(float, float, float);
bool numbers_present(std::string);
bool letters_present(std::string);
bool contains_sub_string(std::string, std::string);
int word_count(std::string);
int word_count(char*);
std::string to_upper(std::string);
std::string to_lower(std::string);
int get_int(std::string);
float get_float(std::string);
std::string get_header(std::string, bool = true);
bool get_yes_no(std::string);
int parse_int(char*);
int parse_int(std::string);
std::string* split_string(std::string);
void write_str_to_file(std::string);
bool strcmpnc(std::string, std::string);
bool strcmpnc(const char*, const char*);
bool contains_array(int, std::string*, int, std::string*);
bool is_file_empty(std::string);

#endif
