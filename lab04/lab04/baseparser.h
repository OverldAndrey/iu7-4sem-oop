#ifndef BASEPARSER_H
#define BASEPARSER_H

#include "object.h"
#include "composite.h"

class BaseParser
{
public:
    BaseParser();

    virtual Object *parse(Composite *) {return nullptr;}
    virtual Object *parse() {return nullptr;}

    virtual void set_file(std::shared_ptr<std::ifstream> fin) = 0;
};

#endif // BASEPARSER_H
