#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "scene.h"

class BaseCommand
{
public:
    BaseCommand();

    virtual std::shared_ptr<BaseProcessResult> execute(Scene &scene) = 0;
};

#endif // BASECOMMAND_H
