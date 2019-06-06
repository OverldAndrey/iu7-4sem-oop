#include "mainprocess.h"
#include "scenebuilder.h"

#include <iostream>

MainProcess::MainProcess()
{
    this->scene = std::shared_ptr<Scene>(new Scene);
    SceneBuilder builder(this->scene.get());

    builder.build_scene();
}

std::shared_ptr<BaseProcessResult> MainProcess::process(BaseCommand &command)
{
    return command.execute(*(this->scene));
}
