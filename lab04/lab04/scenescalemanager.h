#ifndef SCENESCALEMANAGER_H
#define SCENESCALEMANAGER_H

#include "scenetransformmanager.h"

class SceneScaleManager : public SceneTransformManager
{
public:
    SceneScaleManager(Scene *_scene, std::string ids);

    void scale(double kx, double ky, double kz);
};

#endif // SCENESCALEMANAGER_H
