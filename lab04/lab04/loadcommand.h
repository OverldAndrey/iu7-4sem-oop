#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H

#include "basecommand.h"
#include "scene.h"

#include <string>

class LoadCommand : public BaseCommand
{
private:
    std::string fname;
public:
    LoadCommand(const char *fname);

    std::shared_ptr<BaseProcessResult> execute(Scene &scene);
};

#endif // LOADCOMMAND_H
