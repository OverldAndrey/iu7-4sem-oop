#ifndef SCENEDRAWMANAGER_H
#define SCENEDRAWMANAGER_H

#include "scene.h"
#include "basescenemanager.h"

class SceneDrawManager : public BaseSceneManager
{
private:

public:
    SceneDrawManager(Scene *_scene);

    std::shared_ptr<DrawResult> draw();
};

#endif // SCENEDRAWMANAGER_H
