#include "scalecommand.h"

ScaleCommand::ScaleCommand(double kx, double ky, double kz, std::string ids) : TransformCommand(kx, ky, kz, ids)
{

}

std::shared_ptr<BaseProcessResult> ScaleCommand::execute(Scene &scene)
{
    scene.scale(this->x, this->y, this->z, this->ids);
    return std::shared_ptr<BaseProcessResult>(nullptr);
}
