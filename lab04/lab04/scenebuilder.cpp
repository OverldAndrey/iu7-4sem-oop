#include "scenebuilder.h"
#include "sceneloadmanager.h"
#include "scenedrawmanager.h"

#include <iostream>

SceneBuilder::SceneBuilder(Scene *s)
{
    this->scene = s;
}

void SceneBuilder::build_scene()
{
    Camera *cam = new Camera;
    this->scene->add_object(cam);
    auto cam_it = this->scene->begin_cam();
    this->scene->set_cam(cam_it);

    auto load = SceneLoadManager(this->scene);
    std::string loadname("tests.txt");

    load.load_from(loadname);
}
