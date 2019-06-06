#ifndef SCENELOADMANAGER_H
#define SCENELOADMANAGER_H

#include "scene.h"
#include "baseparser.h"
#include "simpleparser.h"
#include"basescenemanager.h"

class SceneLoadManager : public BaseSceneManager
{
private:
    std::shared_ptr<BaseParser> parser;
public:
    SceneLoadManager(Scene *_scene);

    void set_parser(BaseParser *new_parser);

    void load_from(std::string &fname);
};

#endif // SCENELOADMANAGER_H
