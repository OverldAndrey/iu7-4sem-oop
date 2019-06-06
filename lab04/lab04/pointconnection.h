#ifndef POINTCONNECTION_H
#define POINTCONNECTION_H

#include "point.h"

class PointConnection
{
private:
    std::shared_ptr<Point> p1;
    std::shared_ptr<Point> p2;
public:
    PointConnection() = delete;
    PointConnection(Point *_p1, Point *_p2);

    std::shared_ptr<Point> get_p1();
    std::shared_ptr<Point> get_p2();
};

#endif // POINTCONNECTION_H
