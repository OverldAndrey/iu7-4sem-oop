#ifndef SIMPLESAVEPARSER_H
#define SIMPLESAVEPARSER_H

#include "basesaveparser.h"

class SimpleSaveParser : public BaseSaveParser
{
private:
    std::weak_ptr<std::ofstream> file;
public:
    SimpleSaveParser();

    void parse(Object *obj) override;

    void set_file(std::shared_ptr<std::ofstream> fout);
};

#endif // SIMPLESAVEPARSER_H
