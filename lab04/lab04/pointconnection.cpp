#include "pointconnection.h"

PointConnection::PointConnection(Point *_p1, Point *_p2)
{
    this->p1 = std::shared_ptr<Point>(_p1);
    this->p2 = std::shared_ptr<Point>(_p2);
}


std::shared_ptr<Point> PointConnection::get_p1()
{
    return this->p1;
}

std::shared_ptr<Point> PointConnection::get_p2()
{
    return this->p2;
}
