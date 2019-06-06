#include "scenetransformmanager.h"

#include <sstream>

SceneTransformManager::SceneTransformManager(Scene *_scene, std::string _ids) : BaseSceneManager(_scene)
{
    if (_ids.length() > 0)
    {
        std::stringstream ss(_ids);
        std::string item;
        while (std::getline(ss, item, ';')) {
            this->ids.push_back(std::move(item));
        }
    }
}

bool SceneTransformManager::in(size_t id)
{
    for (auto i : this->ids)
    {
        if (std::atof(i.c_str()) == id)
            return true;
    }
    return false;
}
