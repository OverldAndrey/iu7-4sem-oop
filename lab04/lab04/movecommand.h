#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "transformcommand.h"

class MoveCommand : public TransformCommand
{
public:
    MoveCommand(double dx, double dy, double dz, std::string ids);

    std::shared_ptr<BaseProcessResult> execute(Scene &scene);
};

#endif // MOVECOMMAND_H
