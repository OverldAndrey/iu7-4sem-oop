#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "basecommand.h"
#include "drawresult.h"

class DrawCommand : public BaseCommand
{
public:
    DrawCommand();

    std::shared_ptr<BaseProcessResult> execute(Scene &scene);
};

#endif // DRAWCOMMAND_H
