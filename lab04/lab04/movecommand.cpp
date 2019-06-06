#include "movecommand.h"

MoveCommand::MoveCommand(double dx, double dy, double dz, std::string ids) : TransformCommand(dx, dy, dz, ids)
{

}

std::shared_ptr<BaseProcessResult> MoveCommand::execute(Scene &scene)
{
    scene.move(this->x, this->y, this->z, this->ids);
    return std::shared_ptr<BaseProcessResult>(nullptr);
}
