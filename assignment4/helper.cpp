/*********************************************************************
** Program Filename: helper.cpp
** Author: Alexander Nead-Work
** Date: 01/31/2018
** Description: Function implementations for A3
** Input: n/a
** Output: n/a
*********************************************************************/

#include "helper.hpp"

/*********************************************************************
** Function: check_range
** Description: Checks if a given value is within a defined range
** Parameters: int lower_bound, int upper_bound, int test_value
** Pre-Conditions: integer values for the lower & upper bound, and the test value
** Post-Conditions: returns if the test value is in the range or not
*********************************************************************/
bool check_range(int lower_bound, int upper_bound, int test_value) {
	return test_value >= lower_bound && test_value <= upper_bound;
}

/*********************************************************************
** Function: is_int
** Description: Checks if a given string is a valid integer
** Parameters: string num
** Pre-Conditions: the string value
** Post-Conditions: returns if it is a valid integer
*********************************************************************/
bool is_int(std::string num) {
	if ((num[0] < 48 && num[0] != 45) || (num[0] > 57))
		return false;
	for (unsigned int i = 1; i < num.length(); i++) {
		if (!(num[i] >= 48 && num[i] <= 57 )) {
			return false;
		}
	}
	return true;
}

/*********************************************************************
** Function: is_float
** Description: Checks if a given string is a valid float
** Parameters: string num
** Pre-Conditions: the string value
** Post-Conditions: returns if it is a valid float
*********************************************************************/
bool is_float(std::string num) {
	if ((num[0] < 48 && num[0] != 45) || (num[0] > 57))
		return false;
	int decimal_counter = 0;
	for (unsigned int i = 1; i < num.length(); i++) {
		if (num[i] == 46) {
			decimal_counter++;
			if (decimal_counter > 1)
				return false;
		}
		else if (!(num[i] >= 48 && num[i] <= 57 )) {
			return false;
		}
	}
	if (decimal_counter == 0) {
		return false;
	}
	return true;
}

/*********************************************************************
** Function: is_capital
** Description: Checks if a given char is a capital letter
** Parameters: char letter
** Pre-Conditions: the char value
** Post-Conditions: returns if it is a capital letter
*********************************************************************/
bool is_capital(char letter) {
	return letter >= 65 && letter <= 90;
}

/*********************************************************************
** Function: is_even
** Description: Checks if a given integer is even
** Parameters: int num
** Pre-Conditions: the integer value
** Post-Conditions: returns if it is an even number
*********************************************************************/
bool is_even(int num) {
	return num % 2 == 0;
}

/*********************************************************************
** Function: is_odd
** Description: Checks if a given integer is odd
** Parameters: int num
** Pre-Conditions: the integer value
** Post-Conditions: returns if it is an odd number
*********************************************************************/
bool is_odd(int num) {
	return num % 2 == 1;
}

/*********************************************************************
** Function: equality_test
** Description: Describes the equality between two numbers
** Parameters: int num1, int num2
** Pre-Conditions: The two integers that are being tested
** Post-Conditions: The equality value
*********************************************************************/
int equality_test(int num1, int num2) {
	if (num1 < num2) {
		return -1;
	} else if (num1 == num2) {
		return 0;
	} else {
		return 1;
	}
}

/*********************************************************************
** Function: float_is_equal
** Description: Tests if two floats are equal to a given precision value
** Parameters: float num1, float num2, float precision
** Pre-Conditions: The two floats to compare and the precision value
** Post-Conditions: returns if it is equal or not
*********************************************************************/
bool float_is_equal(float num1, float num2, float precision) {
	float diff = std::abs(num1 - num2);
	return diff <= precision;
}

/*********************************************************************
** Function: numbers_present
** Description: Checks if a string has numbers in it
** Parameters: string sentence
** Pre-Conditions: The string to test
** Post-Conditions: returns if there are numbers present
*********************************************************************/
bool numbers_present(std::string sentence) {
	for (unsigned int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 48 && sentence[i] <= 57) {
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: letters_present
** Description: Checks if a string has letters in it
** Parameters: string sentence
** Pre-Conditions: The string to test
** Post-Conditions: returns if there are letters present
*********************************************************************/
bool letters_present(std::string sentence) {
	for (unsigned int i = 0; i < sentence.length(); i++) {
		if ((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)) {
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: contains_sub_string
** Description: Checks if a given substring is in a given string
** Parameters: string sentence, string sub_string
** Pre-Conditions: The sentence and the substring (both strings)
** Post-Conditions: Whether or not the sentence contains the substring
*********************************************************************/
bool contains_sub_string(std::string sentence, std::string sub_string) {
	for (unsigned int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == sub_string[0]) {
			bool found_sub_string = true;
			for (unsigned int j = 0; j < sub_string.length(); j++) {
				if (sentence[i + j] != sub_string[j]) {
					found_sub_string = false;
					break;
				}
			}
			if (found_sub_string) {
				return true;
			}
		}
	}
	return false;
}

/*********************************************************************
** Function: word_count
** Description: Counts the number of words in a string
** Parameters: string sentence || char* sentence
** Pre-Conditions: The sentence
** Post-Conditions: returns the number of words
*********************************************************************/
int word_count(std::string sentence) {
	int num_words = 1;
	for (unsigned int i = 1; i < sentence.length(); i++) {
		if (sentence[i] == ' ' && sentence[i - 1] != ' ')
			num_words++;
		if (i == sentence.length() && sentence[i] != ' ')
			num_words++;
	}
	return num_words;
}
int word_count(char* sentence) {
	int num_words = 1;
	int len = strlen(sentence);
	for (int i = 1; i < len; i++) {
		if (sentence[i] == ' ' && sentence[i - 1] != ' ')
			num_words++;
		if (i == len && sentence[i] != ' ')
			num_words++;
	}
	return num_words;
}

/*********************************************************************
** Function: to_upper
** Description: Returns an all uppercase version of a string
** Parameters: string sentence
** Pre-Conditions: the string to uppercase
** Post-Conditions: returns an uppercase version of the string
*********************************************************************/
std::string to_upper(std::string sentence) {
	for (unsigned int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 97 && sentence[i] <= 122) {
			sentence[i] -= 32;
		}
	}
	return sentence;
}

/*********************************************************************
** Function: to_lower
** Description: Returns an all lowercase version of a string
** Parameters: string sentence
** Pre-Conditions: the string to lowercase
** Post-Conditions: returns an lowercase version of the string
*********************************************************************/
std::string to_lower(std::string sentence) {
	for (unsigned int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 65 && sentence[i] <= 90) {
			sentence[i] += 32;
		}
	}
	return sentence;
}

/*********************************************************************
** Function: get_int
** Description: Gets a valid integer from the user
** Parameters: string prompt
** Pre-Conditions: The prompt for the user
** Post-Conditions: returns an int
*********************************************************************/
int get_int(std::string prompt, bool empty) {
	bool valid_in = true;
	std::string in;
	do {
		if (!valid_in) {
			std::cout << "Invalid input received." << std::endl;
		}

		std::cout << prompt;
		std::getline(std::cin, in);

		valid_in = is_int(in);
	} while (!valid_in && in.length() > 0);
	
	if (in.length() == 0) return -9999;

	//if we get to here, we have a valid int
	int newint = 0;
	for (unsigned int i = 0; i < in.length(); i++) {
		if (in[i] == 48 || in[i] == 45) {
			continue;
		} else {
			newint += (in[i] - 48) * pow(10, in.length() - 1 - i);
		}
	}
	if (in[0] == 45)
		newint *= -1;
	return newint;
}

/*********************************************************************
** Function: get_float
** Description: Gets a valid float from the user
** Parameters: string prompt
** Pre-Conditions: The prompt for the user
** Post-Conditions: returns an float
*********************************************************************/
float get_float(std::string prompt) {
	bool valid_in = true;
	std::string in;
	int decimal_position;
	do {
		if (!valid_in) {
			std::cout << "Invalid input received." << std::endl;
		}

		std::cout << prompt;
		std::getline(std::cin, in);

		valid_in = is_float(in);
	} while (!valid_in);

	//if we get to here, we have a valid float
	for (unsigned int i = 0; i < in.length(); i++) {
		if (in[i] == 46) {
			decimal_position = i;
			break;
		}
	}

	std::string integer = "";
	std::string decimal = "";
	for (int i = 0; i < decimal_position; i++) {
		integer += in[i];
	}
	for (unsigned int i = decimal_position + 1; i < in.length(); i++) {
		decimal += in[i];
	}

	float num = 0;
	for (unsigned int i = 0; i < integer.length(); i++) {
		if (integer[i] == 48 || integer[i] == 45) {
			continue;
		} else {
			num += (integer[i] - 48) * pow(10, integer.length() - 1 - i);
		}
	}
	for (unsigned int i = 0; i < decimal.length(); i++) {
		if (decimal[i] == 48) {
			continue;
		} else {
			int power = -(1 + i);
			num += (decimal[i] - 48) * pow(10, power);
		}
	}
	if (in[0] == 45) {
		num *= -1;
	}
	return num;
}

/*********************************************************************
** Function: get_header
** Description: Generates a nice header for outputting tests to the screen
** Parameters: string message
** Pre-Conditions: The message to be put in the header
** Post-Conditions: returns the header string
*********************************************************************/
std::string get_header(std::string message, bool newline) {
	const int total_line_length = 80;
	const int message_length = message.length();
	int num_dashes = total_line_length - message_length - 2; //2 is the space buffer on either side of the message
	std::string output;

	int left_dash = num_dashes / 2;
	int right_dash;
	if (num_dashes % 2 == 1)
		right_dash = left_dash + 1;
	else
		right_dash = left_dash;

	output = std::string(left_dash, '-') + ' ' + message + ' ' + std::string(right_dash, '-');
	if (newline) output += "\n";
	return output;
}

/*********************************************************************
** Function: get_yes_no
** Description: Asks the user a yes/no question
** Parameters: string prompt
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool get_yes_no(std::string prompt) {
	std::cout << prompt << std::endl;
	std::string input;
	std::getline(std::cin, input);

	if (input == "yes")
		return true;
	if (input == "no")
		return false;
	std::cout << "Invalid input received." << std::endl;
	return get_yes_no(prompt);
}

/*********************************************************************
** Function: parse_int
** Description: Converts a char* to an int
** Parameters: char* str
** Pre-Conditions: str is null-terminated
** Post-Conditions: none
*********************************************************************/
int parse_int(char* str) {
	unsigned int length = strlen(str);
	unsigned int newint = 0;
	for (unsigned int i = 0; i < length; i++) {
		if (str[i] == 48 || str[i] == 45) {
			continue;
		} else {
			newint += (str[i] - 48) * pow(10, length - 1 - i);
		}
	}
	return newint;
}

int parse_int(std::string str) {
	int newint = 0;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == 48 || str[i] == 45) {
			continue;
		} else {
			newint += (str[i] - 48) * pow(10, str.length() - 1 - i);
		}
	}
	return newint;
}

/*********************************************************************
** Function: split_string
** Description: Splits a string on ' '
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
std::string* split_string(std::string str) {
	int num_words = word_count(str);
	std::string* array = new std::string[num_words];
	std::string temp;
	std::stringstream ss(str);
	int counter = 0;
	while (ss >> temp) {
		array[counter] = temp;
		counter++;
	}
	return array;
}

/*********************************************************************
** Function: write_str_to_file
** Description: Writes data to file (prompts for fp)
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void write_str_to_file(std::string data) {
	std::string filepath;
	printf("Please enter a filepath: ");
	getline(std::cin, filepath);

	std::ofstream out;
	out.open(filepath.c_str());
	while (!out.good()) {
		printf("Output filepath is invalid.\n");
		printf("Please enter a filepath: ");
		getline(std::cin, filepath);
		out.close();
		out.open(filepath.c_str());
	}

	out << data;
	out.flush();
	out.close();
}

/*********************************************************************
** Function: strcmpnc
** Description: Compares two strings, disregarding case
** Parameters: string, string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool strcmpnc(std::string a, std::string b) {
	if (a.length() != b.length()) return false;

	for (unsigned int i = 0; i < a.length(); i++) {
		if ((is_capital(a[i]) && is_capital(b[i])) || (!is_capital(a[i]) && !is_capital(b[i]))) {
			if (a[i] != b[i]) return false;
		} else if (is_capital(a[i])) {
			// a[i] is capital, b[i] isn't
			if (a[i] != b[i]-32) return false;
		} else {
			// b[i] is capital, a[i] isn't
			if (a[i]-32 != b[i]) return false;
		}
	}

	return true;
}

/*********************************************************************
** Function: strcmpnc
** Description: Compares two strings, disregarding case
** Parameters: const char*, const char*
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool strcmpnc(const char* a, const char* b) {
	if (strlen(a) != strlen(b)) return false;

	for (unsigned int i = 0; i < strlen(a); i++) {
		if ((is_capital(a[i]) && is_capital(b[i])) || (!is_capital(a[i]) && !is_capital(b[i]))) {
			if (a[i] != b[i]) return false;
		} else if (is_capital(a[i])) {
			// a[i] is capital, b[i] isn't
			if (a[i] != b[i]-32) return false;
		} else {
			// b[i] is capital, a[i] isn't
			if (a[i]-32 != b[i]) return false;
		}
	}

	return true;
}

bool contains_array(int len_haystack, std::string* haystack, int len_needle, std::string* needle) {
	bool* found = new bool[len_needle];
	for (int i = 0; i < len_haystack; i++) {
		for (int j = 0; j < len_needle; j++) {
			if (haystack[i] == needle[j]) {
				found[j] = true;
			}
		}
	}

	bool good = true;
	for (int i = 0; i < len_needle; i++) {
		if (found[i] == false) {
			good = false;
			break;
		}
	}

	delete[] found;
	return good;
}

bool is_file_empty(std::string fname) {
	std::ifstream file;
	file.open(fname.c_str());
	if (file.good()) {
		// file exists
		std::string a;
		getline(file, a);
		if (file.eof() && a.length() == 0) {
			return true;
		}
	}
	file.close();
	return false;
}
