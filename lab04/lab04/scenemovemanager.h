#ifndef SCENEMOVEMANAGER_H
#define SCENEMOVEMANAGER_H

#include "scenetransformmanager.h"

class SceneMoveManager : public SceneTransformManager
{
public:
    SceneMoveManager(Scene *_scene, std::string ids);

    void move(double dx, double dy, double dz);
};

#endif // SCENEMOVEMANAGER_H
