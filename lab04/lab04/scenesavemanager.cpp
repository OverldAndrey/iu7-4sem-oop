#include "scenesavemanager.h"

#include "simplesaveparser.h"
#include "figure.h"

#include <fstream>

SceneSaveManager::SceneSaveManager(Scene *_scene) : BaseSceneManager(_scene)
{
    this->parser = std::shared_ptr<BaseSaveParser>(new SimpleSaveParser);
}

void SceneSaveManager::set_parser(BaseSaveParser *new_parser)
{
    this->parser = std::shared_ptr<BaseSaveParser>(new_parser);
}

void SceneSaveManager::save_to(std::string &fname)
{
    std::shared_ptr<std::ofstream> fout(new std::ofstream(fname));
    this->parser->set_file(fout);

    for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
    {
        auto obj_p = (*(obj_i));
        if (obj_i->get_object()->get_is_drawable())
        {
            auto o = obj_p.get_object().get();
            auto pts = static_cast<Figure*>(o)->get_points_coord();

            for (size_t i = 0; i < pts.size(); i++)
            {
                pts[i] = obj_p.get_transform()->vec_mult(pts[i]);
            }
            static_cast<Figure*>(o)->set_points(pts);

            this->parser->parse(obj_i->get_object().get());

            static_cast<Figure*>(o)->reset_points();
        }
    }

    fout->close();
}
