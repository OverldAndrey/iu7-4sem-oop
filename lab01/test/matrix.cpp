
#include "matrix.h"

void vec_mult(float vec[4], float matr[4][4], float res[4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res[i] += vec[j] * matr[j][i];
        }
    }
}

void matr_mult(float matr1[4][4], float matr2[4][4])
{
    float buf[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    for (int i = 0; i < 4; i++)
    {
        vec_mult(matr1[i], matr2, buf[i]);
    }

    for (int i = 0; i < 16; i++)
    {
        ((float*)matr1)[i] = ((float*)buf)[i];
    }
}
