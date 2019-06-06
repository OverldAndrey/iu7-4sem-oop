#ifndef PROCESS_H
#define PROCESS_H

#include "error.h"

enum Action_codes
{
    init = 0,
    loadf = 1,
    savef = 2,
    movef = 3,
    scalef = 4,
    rotatef = 5,
    rotatecam = 6,
    finish = -1
};

struct Transform
{
    float px = 0;
    float py = 0;
    float pz = 0;
};

struct Action
{
    Action_codes code = init;
    Transform transform;
    const char *fname = nullptr;
};

struct Result
{
    Error_codes error = success;
    void* m = nullptr;
};

Result main_process(Action action);

#endif // PROCESS_H
