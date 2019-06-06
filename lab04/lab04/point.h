#ifndef POINT_H
#define POINT_H

#include "object.h"

#include <vector>

class Point : public Object
{
private:
    double fx = 0;
    double fy = 0;
    double fz = 0;
    double x = 0;
    double y = 0;
    double z = 0;
public:
    Point();
    Point(int x, int y, int z);

    void set(int x, int y, int z);
    void setf(int x, int y, int z);

    double getx() {return this->x;}
    double gety() {return this->y;}
    double getz() {return this->z;}
    std::vector<double> get_coord();
    void reset();

    bool operator ==(Point &p2);
};

#endif // POINT_H
