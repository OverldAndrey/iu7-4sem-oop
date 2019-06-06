#include "pointiterator.h"

PointIterator::PointIterator(FrameFigure *_parent)
{
    this->figure = _parent;
}

Point &PointIterator::operator *()
{
    return *(this->point.lock().get());
}

Point *PointIterator::operator ->()
{
    return this->point.lock().get();
}

PointIterator &PointIterator::operator ++()
{
    this->child_id++;
    if (this->figure->points.size() <= this->child_id)
        this->point = std::shared_ptr<Point>(nullptr);
    else
        this->point = this->figure->points[this->child_id];
    return *this;
}

bool PointIterator::operator !=(PointIterator &iter)
{
    return this->child_id == iter.child_id;
}
