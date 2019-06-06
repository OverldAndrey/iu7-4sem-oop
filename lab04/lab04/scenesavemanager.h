#ifndef SCENESAVEMANAGER_H
#define SCENESAVEMANAGER_H

#include "basescenemanager.h"
#include "basesaveparser.h"

class SceneSaveManager : public BaseSceneManager
{
private:
    std::shared_ptr<BaseSaveParser> parser;
public:
    SceneSaveManager(Scene *_scene);

    void set_parser(BaseSaveParser *new_parser);

    void save_to(std::string &fname);
};

#endif // SCENESAVEMANAGER_H
