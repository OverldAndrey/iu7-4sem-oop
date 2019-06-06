#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "lift.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_callButton_clicked();

    void on_floor1Button_clicked();

    void on_floor2Button_clicked();

    void on_floor3Button_clicked();

    void on_floor4Button_clicked();

    void on_floor5Button_clicked();

    void on_floor6Button_clicked();

    void on_floor7Button_clicked();

    void on_floor8Button_clicked();

    void on_floor9Button_clicked();

    void on_floor10Button_clicked();

public slots:
    void on_lift_move();

    void on_lift_stop(int floor);

    void on_lift_open();

    void on_lift_opening();

    void on_lift_close();

    void on_lift_closing();

    void on_lift_reached_floor(int floor);

signals:
    void panel_button_pressed(int btn);

    void shaft_button_pressed(int floor);

private:
    Ui::MainWindow *ui;
    Lift l;

    QGraphicsScene scene;
    QGraphicsRectItem *lift_item = nullptr;
    QGraphicsRectItem *door1_item = nullptr;
    QGraphicsRectItem *door2_item = nullptr;

    QThread liftThread;
};

#endif // MAINWINDOW_H
