#include "drawresult.h"

DrawResult::DrawResult() : BaseProcessResult()
{
    this->m = std::shared_ptr<QPixmap>(new QPixmap(1600, 900));
}

std::shared_ptr<QPixmap> DrawResult::get_data(int i)
{
    return this->m;
}
