#ifndef STRUCTS
#define STRUCTS

#include <string>

struct employee {
    std::string id;
    std::string first_name;
    std::string last_name;
    std::string password;
};

struct hours {
    std::string day;
    std::string open_hour;
    std::string close_hour;
};

#endif