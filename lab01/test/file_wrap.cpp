#include <cmath>
#include <string>
#include <iostream>

#include "file_wrap.h"
#include "string_wrap.h"
#include "error.h"

bool file_is_open(file_t &f)
{
    return f.is_open();
}

bool is_eof(file_t &f)
{
    return f.eof();
}

void close_file(file_t &f)
{
    f.close();
}

void open_file(file_t &f, const char * const fname)
{
    f.open(fname);
}

Error_codes read_f(file_t &f, float *v)
{
    string_t buf;
    Error_codes err = success;

    f >> buf;
    if (check_str_fl(buf))
    {
        *v = strtofloat(buf);
    }
    else
    {
        err = file_read_error;
    }

    return err;
}

void write_f(file_t &f, float val)
{
    f << val;
}

void write_f(file_t &f, char *val)
{
    f << val;
}
