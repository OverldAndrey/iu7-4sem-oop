#include "scenemovemanager.h"

#include <iostream>

SceneMoveManager::SceneMoveManager(Scene *_scene, std::string ids) : SceneTransformManager(_scene, ids)
{

}

void SceneMoveManager::move(double dx, double dy, double dz)
{
    if (this->ids.size() == 0)
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (obj_i->get_object()->get_is_drawable())
            {
                Matrix matr({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {dx, dy, dz, 1}});

                obj_i->set_transform(matr);
            }
        }
    }
}
