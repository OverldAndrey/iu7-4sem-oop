#include "shaft.h"

Shaft::Shaft() : QObject()
{

}

void Shaft::on_floor_press(int floor)
{
    this->pressed_floors[floor] = true;
    emit floor_update();
}

void Shaft::on_floor_reach(int floor)
{
    this->pressed_floors[floor] = false;
    emit floor_update_false();
}

void Shaft::on_lift_moved(int floor)
{
    this->lift_floor = floor;
}

std::vector<bool> Shaft::get_pressed_floors()
{
    std::vector<bool> res = this->pressed_floors;
    return res;
}
