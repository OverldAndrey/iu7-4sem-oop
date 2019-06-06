#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "matrix.h"

class Camera : public Object
{
private:
    Matrix projection;

public:
    Camera();

    std::vector<std::vector<double>> apply_cam(std::vector<std::vector<double>> &points);

    ~Camera() {}
};

#endif // CAMERA_H
