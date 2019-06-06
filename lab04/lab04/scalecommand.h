#ifndef SCALECOMMAND_H
#define SCALECOMMAND_H

#include "transformcommand.h"

class ScaleCommand : public TransformCommand
{
public:
    ScaleCommand(double kx, double ky, double kz, std::string ids);

    std::shared_ptr<BaseProcessResult> execute(Scene &scene);
};

#endif // SCALECOMMAND_H
