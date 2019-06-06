#ifndef PANEL_H
#define PANEL_H

#include <QObject>

#include <vector>

class Panel : public QObject
{
    Q_OBJECT
private:
    std::vector<bool> pressed_floors = {false, false, false, false, false, false, false, false, false, false, false};
public:
    Panel();

    std::vector<bool> get_pressed_floors();

signals:
    void floor_updated();
    void floor_updated_false();

public slots:
    void on_floor_press(int floor);
    void on_floor_reach(int floor);
};

#endif // PANEL_H
