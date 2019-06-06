#ifndef LOADFILE_H
#define LOADFILE_H

#include "figure.h"
#include "error.h"

using namespace std;

Error_codes load_file(Figure &, const char * const);

Error_codes save_file(Figure &, const char * const);

void clear_points(Figure &fig);

void clear_edges(Figure &fig);

void init_figure(Figure &fig);

Error_codes clear_data(Figure &figure);

#endif // LOADFILE_H
