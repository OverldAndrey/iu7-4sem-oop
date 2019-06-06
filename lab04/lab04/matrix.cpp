#include "matrix.h"

#include <iostream>

//Matrix::Matrix()
//{

//}
Matrix::Matrix(std::initializer_list<std::initializer_list<double> > il)
{
    this->matr.clear();
    for (auto i : il)
    {
        std::vector<double> buf(i);
        this->matr.push_back(buf);
    }
}

std::vector<double> Matrix::vec_mult(std::vector<double>& vec)
{
    std::vector<double> res = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res[i] += vec[j] * this->matr[j][i];
        }
    }

    return res;
}

void Matrix::matr_mult(Matrix& m2)
{
    std::vector<std::vector<double>> buf;

    for (int i = 0; i < 4; i++)
    {
        buf.push_back(m2.vec_mult(this->matr[i]));
    }

    this->matr = buf;
}

void Matrix::operator *(Matrix& m2)
{
    this->matr_mult(m2);
}

std::vector<double> Matrix::operator *(std::vector<double>& vec)
{
    return this->vec_mult(vec);
}

double & Matrix::operator ()(size_t i, size_t j)
{
    return this->matr[i][j];
}
