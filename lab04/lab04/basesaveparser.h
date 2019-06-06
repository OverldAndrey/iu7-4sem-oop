#ifndef BASESAVEPARSER_H
#define BASESAVEPARSER_H

#include "object.h"

#include <fstream>

class BaseSaveParser
{
public:
    BaseSaveParser();

    virtual void parse(Object *) {}

    virtual void set_file(std::shared_ptr<std::ofstream> fout) = 0;
};

#endif // BASESAVEPARSER_H
