#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "scene.h"

class SceneBuilder
{
private:
    Scene *scene;
public:
    SceneBuilder(Scene *s);

    void build_scene();
};

#endif // SCENEBUILDER_H
