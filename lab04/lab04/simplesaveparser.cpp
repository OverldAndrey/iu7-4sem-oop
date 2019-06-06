#include "simplesaveparser.h"

#include "framefigure.h"

SimpleSaveParser::SimpleSaveParser()
{

}

void SimpleSaveParser::set_file(std::shared_ptr<std::ofstream> fout)
{
    this->file = fout;
}

void SimpleSaveParser::parse(Object *obj)
{
    auto pts = static_cast<FrameFigure*>(obj)->get_points_coord();

    for (auto p : pts)
    {
        *(this->file.lock().get()) << p[0] << " " << p[1] << " " << p[2] << '\n';
    }
    *(this->file.lock().get()) << '\n';
}
