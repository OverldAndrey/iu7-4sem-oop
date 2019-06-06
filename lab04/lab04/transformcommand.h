#ifndef TRANSFORMCOMMAND_H
#define TRANSFORMCOMMAND_H

#include "basecommand.h"

class TransformCommand : public BaseCommand
{
protected:
    double x = 0;
    double y = 0;
    double z = 0;
    std::string ids;
public:
    TransformCommand(double x, double y, double z, std::string ids);

    std::shared_ptr<BaseProcessResult> execute(Scene &) {return std::shared_ptr<BaseProcessResult>(nullptr);}
};

#endif // TRANSFORMCOMMAND_H
