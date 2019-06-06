#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "transformcommand.h"

class RotateCommand : public TransformCommand
{
public:
    RotateCommand(double ax, double ay, double az, std::string ids);

    std::shared_ptr<BaseProcessResult> execute(Scene &scene);
};

#endif // ROTATECOMMAND_H
