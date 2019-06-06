#ifndef CABIN_H
#define CABIN_H

#include <QObject>

class Cabin : public QObject
{
    Q_OBJECT
private:
    int current_floor = 1;
    int target_floor = 0;
    bool is_closed = true;
    bool is_moving = false;
    bool is_moving_up = false;
    bool is_moving_down = false;
//    bool is_in_action = false;
    bool doors_are_opening = false;
    bool doors_are_closing = false;
public:
    Cabin();

    int get_current_floor() {return this->current_floor;}
    int get_target_floor() {return this->target_floor;}
    bool get_is_moving() {return this->is_moving;}
    bool get_is_moving_up() {return this->is_moving_up;}
    bool get_is_moving_down() {return this->is_moving_down;}
//    bool get_is_in_action() {return this->is_in_action;}

signals:
    void stop(int floor);
    void reach(int floor);
    void is_opening();
    void open();
    void is_closing();
    void close();

public slots:
    void on_move(int floor);
    void on_stop();
    void on_set_standby();
    void on_standby();
};

#endif // CABIN_H
