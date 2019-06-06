#ifndef SCENETRANSFORMMANAGER_H
#define SCENETRANSFORMMANAGER_H

#include "basescenemanager.h"
#include "objectiterator.h"

class SceneTransformManager : public BaseSceneManager
{
protected:
    std::vector<std::string> ids;

    bool in(size_t id);
public:
    SceneTransformManager(Scene *_scene, std::string ids);
};

#endif // SCENETRANSFORMMANAGER_H
