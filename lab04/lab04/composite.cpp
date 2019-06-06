#include "composite.h"

#include "scene.h"

Composite::Composite() : Object()
{
    this->is_composite = true;
    this->is_drawable = false;
}


ObjectIterator Composite::begin()
{
    ObjectIterator iter(this);
    return iter;
}

ObjectIterator Composite::end()
{
    ObjectIterator iter(this);
    for (size_t i = 0; i < this->children_count; ++iter, i++);
    return iter;
}
