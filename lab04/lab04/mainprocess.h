#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include "scene.h"
#include "basecommand.h"
#include "baseprocessresult.h"

class MainProcess
{
private:
    std::shared_ptr<Scene> scene;
public:
    MainProcess();

    std::shared_ptr<BaseProcessResult> process(BaseCommand &command);
};

#endif // MAINPROCESS_H
