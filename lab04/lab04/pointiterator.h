#ifndef POINTITERATOR_H
#define POINTITERATOR_H

#include "baseobjectiterator.h"
#include "framefigure.h"
#include "point.h"

class FrameFigure;

class PointIterator : public BaseObjectIterator
{
private:
    FrameFigure *figure;
    std::weak_ptr<Point> point;
public:
    PointIterator();
    PointIterator(FrameFigure *_parent);

    Point &operator *();
    Point *operator ->();
    PointIterator &operator ++();
    bool operator !=(PointIterator &iter);
};

#endif // POINTITERATOR_H
