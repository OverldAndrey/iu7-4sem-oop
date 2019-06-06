#ifndef FIGURE_H
#define FIGURE_H

#include <vector>


struct Point
{
    int x = -1;
    int y = -1;
    int z = -1;
    int fx = -1;
    int fy = -1;
    int fz = -1;
};

struct Edge
{
    Point *p1 = nullptr;
    Point *p2 = nullptr;
};

typedef std::vector <Edge*> vedges_t;
typedef std::vector <Point*> vpoints_t;

struct Figure
{
    vedges_t edges;
    vpoints_t points;
    float trmatr[4][4];
    float cammatr[4][4];
    float projmatr[4][4];
};


unsigned int array_size(vpoints_t &points);

unsigned int array_size(vedges_t &edges);

void array_clear(vpoints_t &points);

void array_clear(vedges_t &edges);

void array_push_back(vpoints_t &points, Point *val);

void array_push_back(vedges_t &edges, Edge *val);

void array_copy(vpoints_t &points, vpoints_t &base);

void array_copy(vedges_t &edges, vedges_t &base);

#endif // FIGURE_H
