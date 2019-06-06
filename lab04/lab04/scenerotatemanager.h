#ifndef SCENEROTATEMANAGER_H
#define SCENEROTATEMANAGER_H

#include "scenetransformmanager.h"

class SceneRotateManager : public SceneTransformManager
{
public:
    SceneRotateManager(Scene *_scene, std::string ids);

    void rotate(double ax, double ay, double az);
};

#endif // SCENEROTATEMANAGER_H
