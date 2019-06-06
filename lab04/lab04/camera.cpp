#include "camera.h"

#include <cmath>
#include <iostream>

Camera::Camera() : Object()
{
    const float l = 0.75;
    const float angle = 45;

    this->projection(2, 2) = 0;
    this->projection(2, 0) = -l*cos(angle);
    this->projection(2, 1) = -l*sin(angle);

    this->is_composite = false;
    this->is_drawable = false;
}

std::vector<std::vector<double>> Camera::apply_cam(std::vector<std::vector<double>> &points)
{
    std::vector<std::vector<double>> res;
    for (auto p : points)
    {
        std::vector<double> r1 = {p[0], p[1], p[2], p[3]};
        auto nr1 = projection.vec_mult(r1);
        nr1[0] = nr1[0] + 1600/2;
        nr1[1] = 900/2 - nr1[1];
        std::vector<double> r = {nr1[0], nr1[1], nr1[2], nr1[3]};
        res.push_back(r);
    }

    return res;
}
