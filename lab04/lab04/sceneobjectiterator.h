#ifndef SCENEOBJECTITERATOR_H
#define SCENEOBJECTITERATOR_H

#include "baseobjectiterator.h"

class Scene;

class SceneObjectIterator : public BaseObjectIterator
{
private:
    Scene *scene;
public:
    SceneObjectIterator() = delete;
    SceneObjectIterator(Scene *_ch);

    SceneObjectIterator &operator ++();
    ObjectPosition &operator *();
    ObjectPosition *operator ->();
    bool operator !=(SceneObjectIterator iter);
};

#endif // SCENEOBJECTITERATOR_H
