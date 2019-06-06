#include "savecommand.h"

SaveCommand::SaveCommand(const char *fname) : BaseCommand()
{
    this->fname = fname;
}

std::shared_ptr<BaseProcessResult> SaveCommand::execute(Scene &scene)
{
    scene.save(this->fname);
    return std::shared_ptr<BaseProcessResult>(nullptr);
}
