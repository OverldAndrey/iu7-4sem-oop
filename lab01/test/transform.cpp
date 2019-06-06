#include <cmath>

#include "transform.h"
#include "figure.h"
#include "matrix.h"


void fmove(Figure &fig, float dx, float dy, float dz)
{
    float matr[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {dx, dy, dz, 1}};

    matr_mult(fig.trmatr, matr);
}

void fscale(Figure &fig, float kx, float ky, float kz)
{
    float matr[4][4] = {{kx, 0, 0, 0}, {0, ky, 0, 0}, {0, 0, kz, 0}, {0, 0, 0, 1}};

    matr_mult(fig.trmatr, matr);
}

void frotatex(float matr[4][4], float ax)
{
    float matrx[4][4] = {{1, 0, 0, 0}, {0, cos(ax), sin(ax), 0}, {0, -sin(ax), cos(ax), 0}, {0, 0, 0, 1}};

    matr_mult(matr, matrx);
}

void frotatey(float matr[4][4], float ay)
{
    float matry[4][4] = {{cos(ay), 0, -sin(ay), 0}, {0, 1, 0, 0}, {sin(ay), 0, cos(ay), 0}, {0, 0, 0, 1}};

    matr_mult(matr, matry);
}

void frotatez(float matr[4][4], float az)
{
    float matrz[4][4] = {{cos(az), sin(az), 0, 0}, {-sin(az), cos(az), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    matr_mult(matr, matrz);
}

void frotate(Figure &fig, float ax, float ay, float az)
{
    frotatex(fig.trmatr, ax);
    frotatey(fig.trmatr, ay);
    frotatez(fig.trmatr, az);
}

void frotate_cam(Figure &fig, float ax, float ay, float az)
{
    frotatex(fig.cammatr, ax);
    frotatey(fig.cammatr, ay);
    frotatez(fig.cammatr, az);
}

void transform_points(vpoints_t &points, float matr[4][4])
{
    for (unsigned i = 0; i < points.size(); i++)
    {
        float buf[4] = {points[i]->x, points[i]->y, points[i]->z, 1};
        float res[4] = {0, 0, 0, 0};
        vec_mult(buf, matr, res);
        points[i]->x = res[0];
        points[i]->y = res[1];
        points[i]->z = res[2];
    }
}

void reset_points(vpoints_t &points)
{
    for (unsigned i = 0; i < points.size(); i++)
    {
        points[i]->x = points[i]->fx;
        points[i]->y = points[i]->fy;
        points[i]->z = points[i]->fz;
    }
}

void apply_transform(Figure &fig)
{
    transform_points(fig.points, fig.trmatr);
    transform_points(fig.points, fig.cammatr);
    transform_points(fig.points, fig.projmatr);
}

