#ifndef DRAWRESULT_H
#define DRAWRESULT_H

#include "baseprocessresult.h"

#include <QPainter>

class DrawResult : public BaseProcessResult
{
private:
    std::shared_ptr<QPixmap> m;
public:
    DrawResult();

    std::shared_ptr<QPixmap> get_data(int);
};

#endif // DRAWRESULT_H
