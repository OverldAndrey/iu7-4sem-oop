#include "scenerotatemanager.h"

#include <cmath>

SceneRotateManager::SceneRotateManager(Scene *_scene, std::string ids) : SceneTransformManager(_scene, ids)
{

}

void SceneRotateManager::rotate(double ax, double ay, double az)
{
    if (this->ids.size() == 0)
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (obj_i->get_object()->get_is_drawable())
            {
                Matrix matrx({{1, 0, 0, 0}, {0, cos(ax), sin(ax), 0}, {0, -sin(ax), cos(ax), 0}, {0, 0, 0, 1}});
                Matrix matry({{cos(ay), 0, -sin(ay), 0}, {0, 1, 0, 0}, {sin(ay), 0, cos(ay), 0}, {0, 0, 0, 1}});
                Matrix matrz({{cos(az), sin(az), 0, 0}, {-sin(az), cos(az), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

                obj_i->set_transform(matrx);
                obj_i->set_transform(matry);
                obj_i->set_transform(matrz);
            }
        }
    }
    else
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (this->in(obj_i->get_object()->get_id()))
            {
                Matrix matrx({{1, 0, 0, 0}, {0, cos(ax), sin(ax), 0}, {0, -sin(ax), cos(ax), 0}, {0, 0, 0, 1}});
                Matrix matry({{cos(ay), 0, -sin(ay), 0}, {0, 1, 0, 0}, {sin(ay), 0, cos(ay), 0}, {0, 0, 0, 1}});
                Matrix matrz({{cos(az), sin(az), 0, 0}, {-sin(az), cos(az), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

                obj_i->set_transform(matrx);
                obj_i->set_transform(matry);
                obj_i->set_transform(matrz);
            }
        }
    }
}
