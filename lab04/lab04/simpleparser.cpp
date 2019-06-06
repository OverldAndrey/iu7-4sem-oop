#include "simpleparser.h"
#include "figure.h"

#include <iostream>

SimpleParser::SimpleParser()
{

}

void SimpleParser::set_file(std::shared_ptr<std::ifstream> fin)
{
    this->file = fin;
}

Object *SimpleParser::parse(Composite *parent)
{

}

Object *SimpleParser::parse()
{
    if (this->file.lock()->eof())
        return nullptr;

    std::vector<Point*> buf;

    while (!this->file.lock()->eof())
    {
        unsigned long long x, y, z;

        *(this->file.lock().get()) >> x;
        *(this->file.lock().get()) >> y;
        *(this->file.lock().get()) >> z;

        buf.push_back(new Point(x, y, z));
    }

    auto obj = new Figure(buf[0], buf[1], buf[2], buf[3],
                          buf[4], buf[5], buf[6], buf[7]);

    return obj;
}
