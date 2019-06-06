#include "drawcommand.h"

DrawCommand::DrawCommand() : BaseCommand()
{

}

std::shared_ptr<BaseProcessResult> DrawCommand::execute(Scene &scene)
{
    return scene.draw();
}
