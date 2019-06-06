#include "canvas_wrap.h"
#include "const.h"

float to_canvas_x(float x)
{
    return x + C_WIDTH/2;
}

float to_canvas_y(float y)
{
    return C_HEIGHT/2 - y;
}

void draw_line(canvas_t &canvas, float x1, float y1, float x2, float y2)
{
    canvas.drawLine(to_canvas_x(x1), to_canvas_y(y1), to_canvas_x(x2), to_canvas_y(y2));
}

void init_canvas(canvas_t &canvas, pixmap_t &m)
{
    canvas.begin(&m);
    canvas.setBrush(Qt::white);
    canvas.setPen(Qt::black);
    canvas.drawRect(0, 0, C_WIDTH, C_HEIGHT);
}

void close_canvas(canvas_t &canvas)
{
    canvas.end();
}

pixmap_t *create_pixmap()
{
    pixmap_t *m = new QPixmap(C_WIDTH, C_HEIGHT);
    return m;
}
