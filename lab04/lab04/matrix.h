#ifndef MATRIX_H
#define MATRIX_H


#include <initializer_list>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<double>> matr = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
public:
    Matrix() = default;
    Matrix(std::initializer_list<std::initializer_list<double>>);

    void matr_mult(Matrix& m2);
    std::vector<double> vec_mult(std::vector<double>& vec);

    void operator *(Matrix& m2);
    std::vector<double> operator *(std::vector<double>& vec);
    double &operator ()(size_t i, size_t j);
};

#endif // MATRIX_H
