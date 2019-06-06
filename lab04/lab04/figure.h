#ifndef FIGURE_H
#define FIGURE_H


#include <vector>
#include <memory>
#include <fstream>

#include "matrix.h"
#include "point.h"
#include "framefigure.h"

class Figure : public FrameFigure
{
public:
    Figure(Point *p1, Point *p2, Point *p3, Point *p4,
           Point *p5, Point *p6, Point *p7, Point *p8);

    ~Figure() = default;
};

#endif // FIGURE_H
