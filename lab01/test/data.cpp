#include <cmath>
#include <iostream>

#include "figure.h"
#include "data.h"
#include "transform.h"
#include "drawing.h"
#include "file_wrap.h"
#include "error.h"


void clear_points(Figure &fig)
{
    for (int i = array_size(fig.points) - 1; i >= 0; i--)
    {
        delete fig.points[i];
    }
    array_clear(fig.points);
}

void clear_edges(Figure &fig)
{
    for (int i = array_size(fig.edges) - 1; i >= 0; i--)
    {
        delete fig.edges[i];
    }
    array_clear(fig.edges);
}

void trmatr_init(float m[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void projmatr_init(float m[4][4])
{
    const float l = 0.75;
    const float angle = 45;

    trmatr_init(m);
    m[2][2] = 0;
    m[2][0] = -l*cos(angle);
    m[2][1] = -l*sin(angle);
}

Error_codes fill_point(Point *p, file_t &fin)
{
    float v1 = 0, v2 = 0, v3 = 0;
    Error_codes err = success;

    if (read_f(fin, &v1) != success || read_f(fin, &v2) != success || read_f(fin, &v3) != success)
        err = file_read_error;
    else
    {
        p->x = v1;
        p->y = v2;
        p->z = v3;
        p->fx = p->x;
        p->fy = p->y;
        p->fz = p->z;
    }

    return err;
}

int find_point(vpoints_t &points, Point &p)
{
    int ret = -1;

    for (unsigned i = 0; i < array_size(points) && ret == -1; i++)
    {
        if (points[i]->x == p.x && points[i]->y == p.y && points[i]->z == p.z)
        {
            ret = i;
        }
    }

    return ret;
}

Point *add_point(vpoints_t &points, Point *p)
{
    int i = find_point(points, *p);
    Point *ret = nullptr;

    if (i != -1)
    {
        delete p;
        ret = points[i];
    }
    else
    {
        array_push_back(points, p);
        ret = p;
    }

    return ret;
}

Error_codes fill_edge(Point *p1, Point *p2, Figure &fig)
{
    Edge *e = new(nothrow) Edge;
    Error_codes err = success;

    if (e == nullptr)
        err = alloc_error;
    else
    {
        e->p1 = add_point(fig.points, p1);
        e->p2 = add_point(fig.points, p2);

        array_push_back(fig.edges, e);
    }

    return err;
}

void init_figure(Figure &fig)
{
    clear_points(fig);
    clear_edges(fig);
    trmatr_init(fig.trmatr);
    trmatr_init(fig.cammatr);
    projmatr_init(fig.projmatr);
}

Error_codes set_point_error(Error_codes err, Point *p1, Point *p2)
{
    delete p1;
    delete p2;
    return err;
}

Error_codes check_points_alloc(Point *p1, Point *p2)
{
    Error_codes err = success;

    if (p1 == nullptr || p2 == nullptr)
    {
        err = set_point_error(alloc_error, p1, p2);
    }

    return err;
}

Error_codes fill_point_pair(file_t &fin, Figure &fig, Point *p1, Point *p2)
{
    Error_codes err = success;

    if (fill_point(p1, fin) != success || fill_point(p2, fin) != success)
    {
        err = set_point_error(file_read_error, p1, p2);
    }
    else
    {
        err = fill_edge(p1, p2, fig);
    }

    return err;
}

Error_codes read_point_pair(file_t &fin, Figure &fig)
{
    Point *p1 = new(nothrow) Point;
    Point *p2 = new(nothrow) Point;
    Error_codes err = success;

    err = check_points_alloc(p1, p2);

    if (err == success)
    {
        err = fill_point_pair(fin, fig, p1, p2);
    }

    return err;
}

Error_codes fill_figure(file_t &fin, Figure &fig)
{
    Error_codes err = success;

    while (!is_eof(fin) && err == success)
    {
        err = read_point_pair(fin, fig);
    }

    return err;
}

Error_codes clear_data(Figure &figure)
{
    clear_points(figure);
    clear_edges(figure);

    return success;
}

void copy_figure(Figure &figure, Figure &fig)
{
    init_figure(figure);
    array_copy(figure.points, fig.points);
    array_copy(figure.edges, fig.edges);
}

Error_codes load_file(Figure &figure, const char * const fname)
{
    file_t fin;
    Error_codes error = success;
    Figure fig;

    open_file(fin, fname);

    if (!file_is_open(fin))
    {
        error = file_load_error;
    }
    else
    {
        init_figure(fig);

        error = fill_figure(fin, fig);

        close_file(fin);
    }

    if (error == file_read_error)
        clear_data(fig);

    if (error == success)
        copy_figure(figure, fig);

    return error;
}

void write_edges(file_t &fout, vedges_t &edges)
{
    for (unsigned i = 0; i < array_size(edges); i++)
    {
        Point *p1 = edges[i]->p1;
        Point *p2 = edges[i]->p2;
        write_f(fout, p1->x);
        write_f(fout, " ");
        write_f(fout, p1->y);
        write_f(fout, " ");
        write_f(fout, p1->z);
        write_f(fout, " ");
        write_f(fout, p2->x);
        write_f(fout, " ");
        write_f(fout, p2->y);
        write_f(fout, " ");
        write_f(fout, p2->z);
        if (i < array_size(edges) - 1) {write_f(fout, "\n");}
    }
}

Error_codes save_file(Figure &fig, const char * const fname)
{
    file_t fout;
    Error_codes error = success;

    open_file(fout, fname);

    if (!file_is_open(fout))
    {
        error = file_load_error;
    }
    else
    {
        transform_points(fig.points, fig.trmatr);
        write_edges(fout, fig.edges);

        close_file(fout);
    }

    return error;
}
