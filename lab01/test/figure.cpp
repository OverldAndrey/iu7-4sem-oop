#include "figure.h"

unsigned int array_size(vpoints_t &points)
{
    return points.size();
}

unsigned int array_size(vedges_t &edges)
{
    return edges.size();
}

void array_clear(vpoints_t &points)
{
    points.clear();
}

void array_clear(vedges_t &edges)
{
    edges.clear();
}

void array_push_back(vpoints_t &points, Point *val)
{
    points.push_back(val);
}

void array_push_back(vedges_t &edges, Edge *val)
{
    edges.push_back(val);
}

void array_copy(vpoints_t &points, vpoints_t &base)
{
    points = base;
}

void array_copy(vedges_t &edges, vedges_t &base)
{
    edges = base;
}
