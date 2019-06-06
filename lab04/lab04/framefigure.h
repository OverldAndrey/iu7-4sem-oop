#ifndef FRAMEFIGURE_H
#define FRAMEFIGURE_H

#include "basefigure.h"
#include "pointconnection.h"
#include "pointiterator.h"

class PointIterator;

class FrameFigure : public BaseFigure
{
protected:
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<PointConnection>> edges;

    size_t point_count = 0;

    friend class PointIterator;
public:
    FrameFigure();

    void add_edge(Point *p1, Point *p2);
    std::vector<std::vector<double>> get_edges();
    std::vector<std::vector<double>> get_points_coord();
    std::vector<std::shared_ptr<Point>> &get_points();

    void set_points(std::vector<std::vector<double>> points);
    void reset_points();

    PointIterator begin();
    PointIterator end();
};

#endif // FRAMEFIGURE_H
