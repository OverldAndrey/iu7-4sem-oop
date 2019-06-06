#include "point.h"

Point::Point(int x, int y, int z)
{
    this->setf(x, y, z);
    this->set(x, y, z);

    this->is_composite = false;
    this->is_drawable = true;
}

bool Point::operator ==(Point &p2)
{
    return this->x == p2.x && this->y == p2.y && this->z == p2.z;
}

void Point::set(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::setf(int x, int y, int z)
{
    this->fx = x;
    this->fy = y;
    this->fz = z;
}

void Point::reset()
{
    this->x = this->fx;
    this->y = this->fy;
    this->z = this->fz;
}

std::vector<double> Point::get_coord()
{
    std::vector<double> res = {this->getx(), this->gety(), this->getz(), 0};
    return res;
}
