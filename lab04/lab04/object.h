#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

#include "abstractobject.h"


class Object : public AbstractObject
{
protected:
    bool is_drawable = false;
    bool is_composite = false;
public:
    Object();

    size_t get_id() override;
    bool get_is_drawable();
    bool get_is_composite();
};

#endif // OBJECT_H
