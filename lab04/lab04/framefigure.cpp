#include "framefigure.h"

FrameFigure::FrameFigure() : BaseFigure()
{

}


void FrameFigure::add_edge(Point *p1, Point *p2)
{
    std::shared_ptr<PointConnection> con(new PointConnection(p1, p2));
    this->edges.push_back(con);
}

std::vector<std::vector<double>> FrameFigure::get_edges()
{
    std::vector<std::vector<double>> res;

    for (auto e : edges)
    {
        std::vector<double> tmp = {e->get_p1()->getx(), e->get_p1()->gety(), e->get_p1()->getz(), 0,
                                   e->get_p2()->getx(), e->get_p2()->gety(), e->get_p2()->getz(), 0};
        res.push_back(tmp);
    }

    return res;
}

std::vector<std::vector<double>> FrameFigure::get_points_coord()
{
    std::vector<std::vector<double>> res;

    for (auto p : points)
    {
        std::vector<double> tmp = {p->getx(), p->gety(), p->getz(), 1};
        res.push_back(tmp);
    }

    return res;
}

std::vector<std::shared_ptr<Point>> &FrameFigure::get_points()
{
    return this->points;
}

void FrameFigure::set_points(std::vector<std::vector<double>> points)
{
    for (size_t i = 0; i < points.size(); i++)
    {
        auto p = this->points[i];

        p->set(points[i][0], points[i][1], points[i][2]);
    }
}

void FrameFigure::reset_points()
{
    for (auto p : this->points)
    {
        p->reset();
    }
}

PointIterator FrameFigure::begin()
{
    PointIterator iter(this);
    return iter;
}

PointIterator FrameFigure::end()
{
    PointIterator iter(this);
    for (size_t i = 0; i < this->point_count; ++iter, i++);
    return iter;
}
