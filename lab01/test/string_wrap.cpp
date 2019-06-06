#include <cmath>

#include "string_wrap.h"


unsigned long long int str_length(string_t &str)
{
    return str.length();
}

long long int str_find(string_t &str, char c)
{
    return (str.find(c) == std::string::npos) ? -1 : str.find(c);
}

bool check_str_fl(string_t &str)
{
    if (str[0] != '-' and (str[0] < '0' or str[0] > '9'))
        return false;

    for (int i = 1; i < str_length(str); i++)
        if ((str[i] < '0' or str[i] > '9') && str[i] != '.')
            return false;

    return true;
}

float strtofloat(string_t &str)
{
    float res = 0;
    int i;
    long long dot = str_find(str, '.');

    if (str[0] == '-')
        i = 1;
    else
        i = 0;

    if (dot == NPOS)
        dot = str_length(str);

    for (; i < dot; i++)
    {
        res = res*10 + (str[i]-'0');
    }

    for (i = dot + 1; i < str_length(str); i++)
    {
        res = res + (str[i]-'0')*powf(0.1, (i-dot));
    }

    if (str[0] == '-')
        res = -res;

    return res;
}
