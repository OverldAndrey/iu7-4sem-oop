#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

#include "baseparser.h"
#include "point.h"

class SimpleParser : public BaseParser
{
private:
    std::weak_ptr<std::ifstream> file;
public:
    SimpleParser();

    Object *parse(Composite *parent) override;
    Object *parse() override;

    void set_file(std::shared_ptr<std::ifstream> fin);
};

#endif // SIMPLEPARSER_H
