#include "loadcommand.h"

#include <iostream>

LoadCommand::LoadCommand(const char *fname) : BaseCommand()
{
    this->fname = fname;
}

std::shared_ptr<BaseProcessResult> LoadCommand::execute(Scene &scene)
{
    scene.load(this->fname);
    return std::shared_ptr<BaseProcessResult>(nullptr);
}
