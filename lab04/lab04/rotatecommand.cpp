#include "rotatecommand.h"

RotateCommand::RotateCommand(double ax, double ay, double az, std::string ids) : TransformCommand(ax, ay, az, ids)
{

}

std::shared_ptr<BaseProcessResult> RotateCommand::execute(Scene &scene)
{
    scene.rotate(this->x, this->y, this->z, this->ids);
    return std::shared_ptr<BaseProcessResult>(nullptr);
}
