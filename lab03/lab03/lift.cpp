#include "lift.h"

#include <QtConcurrent/QtConcurrent>
#include <iostream>

Lift::Lift() :
    QObject()
{
    cabin.moveToThread(&cabinThread);
    panel.moveToThread(&panelThread);
    shaft.moveToThread(&shaftThread);

    QObject::connect(this, &Lift::lift_panel_button_pressed, &panel, &Panel::on_floor_press);
    QObject::connect(this, &Lift::lift_shaft_button_pressed, &shaft, &Shaft::on_floor_press);
    QObject::connect(&panel, &Panel::floor_updated, this, &Lift::on_button_update);
    QObject::connect(&panel, &Panel::floor_updated_false, this, &Lift::on_button_update);
    QObject::connect(&shaft, &Shaft::floor_update, this, &Lift::on_button_update);

    QObject::connect(&cabin, &Cabin::reach, &panel, &Panel::on_floor_reach);
    QObject::connect(&cabin, &Cabin::reach, &shaft, &Shaft::on_floor_reach);
    QObject::connect(this, &Lift::lift_set_target, &cabin, &Cabin::on_move);
    QObject::connect(this, &Lift::lift_on_standby, &cabin, &Cabin::on_standby);
    QObject::connect(this, &Lift::lift_set_target, this, &Lift::on_lift_move);
    QObject::connect(this, &Lift::lift_set_standby, &cabin, &Cabin::on_set_standby);

    QObject::connect(&cabin, &Cabin::reach, this, &Lift::on_cabin_move);
    QObject::connect(&cabin, &Cabin::stop, this, &Lift::on_cabin_stop);
    QObject::connect(&cabin, &Cabin::stop, &cabin, &Cabin::on_stop);
    QObject::connect(&cabin, &Cabin::is_opening, this, &Lift::on_cabin_opening);
    QObject::connect(&cabin, &Cabin::open, this, &Lift::on_cabin_open);
    QObject::connect(&cabin, &Cabin::is_closing, this, &Lift::on_cabin_closing);
    QObject::connect(&cabin, &Cabin::close, this, &Lift::on_cabin_close);

    cabinThread.start();
    panelThread.start();
    shaftThread.start();
}

Lift::~Lift()
{
    cabinThread.quit();
    cabinThread.wait();
    panelThread.quit();
    panelThread.wait();
    shaftThread.quit();
    shaftThread.wait();
}

void Lift::on_panel_button_pressed(int btn)
{
    emit lift_panel_button_pressed(btn);
}

void Lift::on_shaft_button_pressed(int floor)
{
    emit lift_shaft_button_pressed(floor);
}

void Lift::on_button_update()
{
    auto pf = panel.get_pressed_floors();
    auto sf = shaft.get_pressed_floors();
    std::vector<bool> rf(10);

    for (int i = 1; i < pf.size(); i++)
    {
        rf[i-1] = pf[i]|sf[i];
    }

    int cf = cabin.get_current_floor();

//    int f = 0;
//    _search_above(rf, f, 0);

//    if (!f)
//    {
//        int f = 0;
//        _search_above(rf, f, 0);
////        std::cout << f << std::endl;
////        for (auto e : rf)
////            std::cout << e;
////        std::cout << std::endl;
//        if (f)
//        {
//            if (f != cf)
//                emit lift_set_target(f);
//            else
//                emit lift_on_standby();
//        }
//    }
//    else
    {
        if (cabin.get_is_moving_up())
        {
            int f = 0;
            _search_above(rf, f, cf);
            std::cout << f << std::endl;
            if (f)
                emit lift_set_target(f);
            else
            {
                _search_below(rf, f, cf);
                if (f)
                    emit lift_set_target(f);
                else
                    emit lift_set_standby();
            }
        }
        else if (cabin.get_is_moving_down())
        {
            int f = 0;
            _search_below(rf, f, cf);
            if (f)
                emit lift_set_target(f);
            else
            {
                _search_above(rf, f, cf);
                if (f)
                    emit lift_set_target(f);
                else
                    emit lift_set_standby();
            }
        }
        else
        {
            int f = 0;
            _search_above(rf, f, 0);
    //        std::cout << f << std::endl;
    //        for (auto e : rf)
    //            std::cout << e;
    //        std::cout << std::endl;
            if (f)
            {
                if (f != cf)
                    emit lift_set_target(f);
                else
                    emit lift_on_standby();
            }
        }
    }
}

void Lift::on_lift_move()
{
    emit lift_moved();
}

void Lift::on_cabin_move(int floor)
{
    emit lift_on_floor(floor);
}

void Lift::on_cabin_stop(int floor)
{
    emit lift_stopped(floor);
}

void Lift::on_cabin_opening()
{
    emit lift_opening();
}

void Lift::on_cabin_open()
{
    emit lift_opened();
}

void Lift::on_cabin_closing()
{
    emit lift_closing();
}

void Lift::on_cabin_close()
{
    emit lift_closed();
}


void Lift::_search_above(std::vector<bool> &rf, int &f, int cf)
{
    for (int i = cf; i < rf.size(); i++)
    {
        if (rf[i]) {f = i+1; break;}
    }
}

void Lift::_search_below(std::vector<bool> &rf, int &f, int cf)
{
    for (int i = cf-2; i > -1; i--)
    {
        if (rf[i]) {f = i+1; break;}
    }
}
