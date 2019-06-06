#include "object.h"

Object::Object()
{

}

size_t Object::get_id()
{
    return this->id;
}

bool Object::get_is_drawable()
{
    return this->is_drawable;
}

bool Object::get_is_composite()
{
    return this->is_composite;
}
