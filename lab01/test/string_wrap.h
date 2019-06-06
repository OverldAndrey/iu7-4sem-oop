#ifndef STRING_WRAP_H
#define STRING_WRAP_H

#include <string>

typedef std::string string_t;


#define NPOS -1


unsigned long long int str_length(string_t &str);

long long int str_find(string_t &str, char c);

bool check_str_fl(string_t &str);

float strtofloat(string_t &str);

#endif // STRING_WRAP_H
