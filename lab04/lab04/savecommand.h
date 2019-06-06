#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "basecommand.h"

class SaveCommand : public BaseCommand
{
private:
    std::string fname;
public:
    SaveCommand(const char *fname);

    std::shared_ptr<BaseProcessResult> execute(Scene &scene);
};

#endif // SAVECOMMAND_H
