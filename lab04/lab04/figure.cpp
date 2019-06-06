#include "figure.h"

#include <cmath>

#include <iostream>

Figure::Figure(Point *p1, Point *p2, Point *p3, Point *p4,
               Point *p5, Point *p6, Point *p7, Point *p8) : FrameFigure()
{
    this->points.push_back(std::shared_ptr<Point>(p1));
    this->points.push_back(std::shared_ptr<Point>(p2));
    this->points.push_back(std::shared_ptr<Point>(p3));
    this->points.push_back(std::shared_ptr<Point>(p4));
    this->points.push_back(std::shared_ptr<Point>(p5));
    this->points.push_back(std::shared_ptr<Point>(p6));
    this->points.push_back(std::shared_ptr<Point>(p7));
    this->points.push_back(std::shared_ptr<Point>(p8));

    this->add_edge(p1, p2);
    this->add_edge(p2, p3);
    this->add_edge(p3, p4);
    this->add_edge(p4, p1);
    this->add_edge(p1, p5);
    this->add_edge(p2, p6);
    this->add_edge(p3, p7);
    this->add_edge(p4, p8);
    this->add_edge(p5, p6);
    this->add_edge(p6, p7);
    this->add_edge(p7, p8);
    this->add_edge(p8, p5);
}

