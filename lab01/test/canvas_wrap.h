#ifndef CANVAS_WRAP_H
#define CANVAS_WRAP_H

#include <QPainter>

typedef QPixmap pixmap_t;

typedef QPainter canvas_t;


void draw_line(canvas_t &canvas, float x1, float y1, float x2, float y2);

void init_canvas(canvas_t &canvas, pixmap_t &m);

void close_canvas(canvas_t &canvas);

pixmap_t *create_pixmap();


#endif // CANVAS_WRAP_H
