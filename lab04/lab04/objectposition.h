#ifndef OBJECTPOSITION_H
#define OBJECTPOSITION_H

#include "matrix.h"
#include "object.h"

#include <memory>

class ObjectPosition
{
    double x = 0;
    double y = 0;
    double z = 0;

    Matrix transform;

    std::shared_ptr<Object> object;
public:
    ObjectPosition();
    ObjectPosition(Object *obj);

    Matrix *get_transform();
    void set_transform(Matrix &m);

    std::vector<double> get_position();
    void set_position(double x, double y, double z);

    std::shared_ptr<Object> get_object();
};

#endif // OBJECTPOSITION_H
