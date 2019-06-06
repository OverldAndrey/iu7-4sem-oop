#include "objectposition.h"

ObjectPosition::ObjectPosition()
{

}

ObjectPosition::ObjectPosition(Object *obj)
{
    this->object = std::shared_ptr<Object>(obj);
}

Matrix *ObjectPosition::get_transform()
{
    return &(this->transform);
}

void ObjectPosition::set_transform(Matrix &m)
{
    this->transform.matr_mult(m);
}

std::vector<double> ObjectPosition::get_position()
{
    std::vector<double> res = {this->x, this->y, this->z, 1};
    return res;
}

void ObjectPosition::set_position(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

std::shared_ptr<Object> ObjectPosition::get_object()
{
    return this->object;
}
