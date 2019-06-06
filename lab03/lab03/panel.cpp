#include "panel.h"

#include <iostream>

Panel::Panel() : QObject()
{

}

void Panel::on_floor_press(int floor)
{
    this->pressed_floors[floor] = true;
    emit floor_updated();
}

void Panel::on_floor_reach(int floor)
{
    this->pressed_floors[floor] = false;
    emit floor_updated_false();
}

std::vector<bool> Panel::get_pressed_floors()
{
    std::vector<bool> res = this->pressed_floors;
    return res;
}
