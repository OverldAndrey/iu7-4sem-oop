#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QThread>

#include "panel.h"
#include "cabin.h"
#include "shaft.h"

class Lift : public QObject
{
    Q_OBJECT
private:
    Panel panel;
    Cabin cabin;
    Shaft shaft;

    QThread cabinThread;
    QThread panelThread;
    QThread shaftThread;

    void _search_above(std::vector<bool> &rf, int &f, int cf);
    void _search_below(std::vector<bool> &rf, int &f, int cf);

public:
    Lift();
    ~Lift();

public slots:
    void on_panel_button_pressed(int btn);
    void on_shaft_button_pressed(int floor);

    void on_button_update();
    void on_lift_move();

    void on_cabin_stop(int floor);
    void on_cabin_move(int floor);
    void on_cabin_opening();
    void on_cabin_open();
    void on_cabin_closing();
    void on_cabin_close();

signals:
    void lift_panel_button_pressed(int floor);
    void lift_shaft_button_pressed(int floor);

    void lift_set_target(int floor);
    void lift_set_standby();
    void lift_on_standby();

    void lift_moved();
    void lift_stopped(int floor);
    void lift_opened();
    void lift_opening();
    void lift_closed();
    void lift_closing();
    void lift_on_floor(int floor);
};

#endif // LIFT_H
