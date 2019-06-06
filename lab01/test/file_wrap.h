#ifndef FILE_WRAP_H
#define FILE_WRAP_H

#include <fstream>

typedef std::fstream file_t;


bool file_is_open(file_t &f);

bool is_eof(file_t &f);

void close_file(file_t &f);

void open_file(file_t &f, const char * const fname);

Error_codes read_f(file_t &f, float *v);

void write_f(file_t &f, float val);

void write_f(file_t &f, char *val);

#endif // FILE_WRAP_H
