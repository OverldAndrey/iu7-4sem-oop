#ifndef BASESCENEMANAGER_H
#define BASESCENEMANAGER_H

#include "scene.h"

class BaseSceneManager
{
protected:
    Scene *scene;
public:
    BaseSceneManager(Scene *_scene);
};

#endif // BASESCENEMANAGER_H
