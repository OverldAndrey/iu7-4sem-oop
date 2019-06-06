#include "sceneloadmanager.h"

#include <fstream>

#include <iostream>

SceneLoadManager::SceneLoadManager(Scene *_scene) : BaseSceneManager(_scene)
{
    this->parser = std::shared_ptr<BaseParser>(new SimpleParser);
}

void SceneLoadManager::set_parser(BaseParser *new_parser)
{
    this->parser = std::shared_ptr<BaseParser>(new_parser);
}

void SceneLoadManager::load_from(std::string &fname)
{
    std::shared_ptr<std::ifstream> fin(new std::ifstream(fname));
    this->parser->set_file(fin);

    while (true)
    {
        Object *obj = this->parser->parse();

        if (obj == nullptr)
            break;

        this->scene->add_object(obj);
    }

    fin->close();
}
