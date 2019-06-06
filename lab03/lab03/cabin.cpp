#include "cabin.h"

#include <iostream>

#include <QThread>
#include <QTimer>

Cabin::Cabin() : QObject()
{

}


void Cabin::on_move(int floor)
{
    this->target_floor = floor;
    if (this->target_floor == this->current_floor)
    {
        return;
    }

//    std::cout << this->current_floor << " " << this->target_floor << std::endl;
    this->is_moving = true;
//    this->is_in_action = true;

    if (this->current_floor < this->target_floor)
    {
        this->is_moving_down = false;
        this->is_moving_up = true;
        this->current_floor++;
    }
    else if (this->current_floor > this->target_floor)
    {
        this->is_moving_down = true;
        this->is_moving_up = false;
        this->current_floor--;
    }

    for (int i = 0; i < 500; i++)
    {
        QThread::msleep(1);
    }

    emit reach(this->current_floor);

    if (this->current_floor == this->target_floor)
    {
        this->is_moving = false;
        emit stop(this->current_floor);
    }
}

void Cabin::on_stop()
{
    this->is_closed = false;
    for (int i = 0; i < 200; i++)
    {
        QThread::msleep(1);
    }
    this->doors_are_opening = true;
    emit is_opening();
    for (int i = 0; i < 200; i++)
    {
        QThread::msleep(1);
    }
    this->doors_are_opening = false;
    emit open();
    for (int i = 0; i < 200; i++)
    {
        QThread::msleep(1);
    }
    this->doors_are_closing = true;
    emit is_closing();
    for (int i = 0; i < 200; i++)
    {
        QThread::msleep(1);
    }
    this->doors_are_closing = false;
    this->is_closed = true;
    emit close();
}

void Cabin::on_set_standby()
{
    this->is_moving_down = false;
    this->is_moving_up = false;
//    this->is_in_action = false;
}

void Cabin::on_standby()
{
    emit reach(this->current_floor);
    emit stop(this->current_floor);
}
