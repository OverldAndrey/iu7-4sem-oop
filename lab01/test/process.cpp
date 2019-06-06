#include "figure.h"
#include "data.h"
#include "drawing.h"
#include "transform.h"
#include "process.h"


Result initialize_figure(Figure &figure);

Result load_file_data(Figure &figure, Action &action);

Result save_file_data(Figure &figure, Action &action);

Result move_figure(Figure &figure, Action &action);

Result scale_figure(Figure &figure, Action &action);

Result rotate_figure(Figure &figure, Action &action);

Result rotate_camera(Figure &figure, Action &action);

Result delete_figure(Figure &figure);

Result unknown_command();


Result main_process(Action action)
{
    static Figure figure;
    Result result;

    switch (action.code)
    {
    case init:
        result = initialize_figure(figure);
        break;
    case loadf:
        result = load_file_data(figure, action);
        break;
    case savef:
        result = save_file_data(figure, action);
        break;
    case movef:
        result = move_figure(figure, action);
        break;
    case scalef:
        result = scale_figure(figure, action);
        break;
    case rotatef:
        result = rotate_figure(figure, action);
        break;
    case rotatecam:
        result = rotate_camera(figure, action);
        break;
    case finish:
        result = delete_figure(figure);
        break;
    default:
        result = unknown_command();
        break;
    }

    return result;
}


Result initialize_figure(Figure &figure)
{
    Result result = {.error = success, .m = nullptr};
    init_figure(figure);
    return result;
}

Result load_file_data(Figure &figure, Action &action)
{
    Result result = {.error = success, .m = nullptr};
    result.error = load_file(figure, action.fname);
    if (result.error == success)
        result.m = set_canvas(figure);
    return result;
}

Result save_file_data(Figure &figure, Action &action)
{
    Result result = {.error = success, .m = nullptr};
    result.error = save_file(figure, action.fname);
    return result;
}

Result move_figure(Figure &figure, Action &action)
{
    Result result = {.error = success, .m = nullptr};
    Transform tr = action.transform;
    fmove(figure, tr.px, tr.py, tr.pz);
    result.m = set_canvas(figure);
    return result;
}

Result scale_figure(Figure &figure, Action &action)
{
    Result result = {.error = success, .m = nullptr};
    Transform tr = action.transform;
    fscale(figure, tr.px, tr.py, tr.pz);
    result.m = set_canvas(figure);
    return result;
}

Result rotate_figure(Figure &figure, Action &action)
{
    Result result = {.error = success, .m = nullptr};
    Transform tr = action.transform;
    frotate(figure, tr.px, tr.py, tr.pz);
    result.m = set_canvas(figure);
    return result;
}

Result rotate_camera(Figure &figure, Action &action)
{
    Result result = {.error = success, .m = nullptr};
    Transform tr = action.transform;
    frotate_cam(figure, tr.px, tr.py, tr.pz);
    result.m = set_canvas(figure);
    return result;
}

Result delete_figure(Figure &figure)
{
    Result result = {.error = success, .m = nullptr};
    result.error = clear_data(figure);
    return result;
}

Result unknown_command()
{
    Result result = {.error = unknown_command_error, .m = nullptr};
    return result;
}
