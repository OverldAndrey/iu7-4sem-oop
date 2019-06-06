#include "sceneobjectiterator.h"

#include "scene.h"

SceneObjectIterator::SceneObjectIterator(Scene *_ch)
{
    this->scene = _ch;
    this->current_child = this->scene->objects[0];
}

SceneObjectIterator &SceneObjectIterator::operator ++()
{
    this->child_id++;
    if (this->child_id >= this->scene->objects.size())
        this->current_child = std::shared_ptr<ObjectPosition>(nullptr);
    else
        this->current_child = this->scene->objects[this->child_id];
    return *this;
}

ObjectPosition &SceneObjectIterator::operator *()
{
    return *(this->current_child.lock());
}

ObjectPosition *SceneObjectIterator::operator ->()
{
    return this->current_child.lock().get();
}

bool SceneObjectIterator::operator !=(SceneObjectIterator iter)
{
    return this->child_id != iter.child_id;
}
