#include "scenescalemanager.h"

SceneScaleManager::SceneScaleManager(Scene *_scene, std::string ids) : SceneTransformManager(_scene, ids)
{

}

void SceneScaleManager::scale(double kx, double ky, double kz)
{
    if (this->ids.size() == 0)
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (obj_i->get_object()->get_is_drawable())
            {
                Matrix matr({{kx, 0, 0, 0}, {0, ky, 0, 0}, {0, 0, kz, 0}, {0, 0, 0, 1}});

                obj_i->set_transform(matr);
            }
        }
    }
}
