#ifndef SHAFT_H
#define SHAFT_H

#include <QObject>

#include <vector>

class Shaft : public QObject
{
    Q_OBJECT
private:
    std::vector<bool> pressed_floors = {false, false, false, false, false, false, false, false, false, false, false};
    int lift_floor = 1;
public:
    Shaft();

    std::vector<bool> get_pressed_floors();

signals:
    void floor_update();
    void floor_update_false();

public slots:
    void on_floor_press(int floor);
    void on_floor_reach(int floor);
    void on_lift_moved(int floor);
};

#endif // SHAFT_H
