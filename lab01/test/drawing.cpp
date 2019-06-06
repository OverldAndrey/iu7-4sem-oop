#include <QPainter>

#include "drawing.h"
#include "figure.h"
#include "transform.h"
#include "data.h"
#include "const.h"
#include "canvas_wrap.h"


void draw_fig(canvas_t &canvas, Figure &fig)
{
    apply_transform(fig);
    for (unsigned i = 0; i < array_size(fig.edges); i++)
    {
        Point *p1 = fig.edges[i]->p1;
        Point *p2 = fig.edges[i]->p2;
        draw_line(canvas, p1->x, p1->y, p2->x, p2->y);
    }
    reset_points(fig.points);
}

pixmap_t *set_canvas(Figure &figure)
{
    pixmap_t *m = create_pixmap();
    canvas_t canvas;

    init_canvas(canvas, *m);
    draw_fig(canvas, figure);
    close_canvas(canvas);

    return m;
}
