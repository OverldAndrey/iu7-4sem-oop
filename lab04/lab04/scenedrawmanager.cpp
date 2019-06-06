#include "scenedrawmanager.h"
#include "figure.h"

#include <QPainter>

#include <string.h>
#include <iostream>

SceneDrawManager::SceneDrawManager(Scene *_scene) : BaseSceneManager(_scene)
{

}

std::shared_ptr<DrawResult> SceneDrawManager::draw()
{
    std::shared_ptr<DrawResult> res = std::shared_ptr<DrawResult>(new DrawResult);

    QPainter canvas(res->get_data(0).get());
    canvas.setBrush(Qt::white);
    canvas.setPen(Qt::black);
    canvas.drawRect(0, 0, 1600, 900);

    for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
    {
        auto obj_p = (*(obj_i));
        if (obj_p.get_object()->get_is_drawable())
        {
            auto o = obj_p.get_object().get();
            auto cam = this->scene->get_current_camera();
            auto pts = static_cast<Figure*>(o)->get_points_coord();

            for (size_t i = 0; i < pts.size(); i++)
            {
                pts[i] = obj_p.get_transform()->vec_mult(pts[i]);
                pts[i] = cam->get_transform()->vec_mult(pts[i]);
            }
//            for (auto p : pts)
//            {
//                std::cout << p[0] << " " << p[1] << " " << p[2] << std::endl;
//            }

            pts = static_cast<Camera*>(cam->get_object().get())->apply_cam(pts);
            static_cast<Figure*>(o)->set_points(pts);

            auto coord = static_cast<Figure*>(o)->get_edges();
            for (auto e : coord)
            {
                canvas.drawLine(e[0], e[1], e[4], e[5]);
            }

            static_cast<Figure*>(o)->reset_points();
        }
    }
    canvas.end();

    return res;
}
