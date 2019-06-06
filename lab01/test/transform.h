#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "figure.h"

void fmove(Figure &, float, float, float);

void fscale(Figure &, float, float, float);

void frotate(Figure &, float, float, float);

void frotate_cam(Figure &, float, float, float);

void transform_points(vpoints_t &, float matr[4][4]);

void reset_points(vpoints_t &);

void apply_transform(Figure &fig);

#endif // TRANSFORM_H
