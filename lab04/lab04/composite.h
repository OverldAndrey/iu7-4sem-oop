#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"
#include "objectposition.h"
#include "objectiterator.h"
#include <vector>

class Scene;

class Composite : public Object
{
private:
    size_t children_count = 0;

    std::vector<std::shared_ptr<ObjectPosition>> children;

    friend class ObjectIterator;
public:
    Composite();

    ObjectIterator begin();
    ObjectIterator end();
};

#endif // COMPOSITE_H
