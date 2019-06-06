#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    l.moveToThread(&liftThread);

    QObject::connect(&l, &Lift::lift_moved, this, &MainWindow::on_lift_move);
    QObject::connect(&l, &Lift::lift_stopped, this, &MainWindow::on_lift_stop);
    QObject::connect(&l, &Lift::lift_on_floor, this, &MainWindow::on_lift_reached_floor);
    QObject::connect(&l, &Lift::lift_opened, this, &MainWindow::on_lift_open);
    QObject::connect(&l, &Lift::lift_closed, this, &MainWindow::on_lift_close);
    QObject::connect(&l, &Lift::lift_opening, this, &MainWindow::on_lift_opening);
    QObject::connect(&l, &Lift::lift_closing, this, &MainWindow::on_lift_closing);
    QObject::connect(this, &MainWindow::panel_button_pressed, &l, &Lift::on_panel_button_pressed);
    QObject::connect(this, &MainWindow::shaft_button_pressed, &l, &Lift::on_shaft_button_pressed);

    liftThread.start();

    this->setUpdatesEnabled(true);

    scene.setSceneRect(0, 0, 960, 640);

    QRect lift(450, 560, 60, 60);
    QRect door1(450, 560, 30, 60);
    QRect door2(480, 560, 30, 60);

    lift_item = scene.addRect(lift);
    door1_item = scene.addRect(door1);
    door2_item = scene.addRect(door2);

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    liftThread.quit();
    liftThread.wait();
    delete ui;
}

void MainWindow::on_callButton_clicked()
{
    int f = ui->callEdit->text().toInt();
    emit shaft_button_pressed(f);
}

void MainWindow::on_floor1Button_clicked()
{
    emit panel_button_pressed(1);
}

void MainWindow::on_floor2Button_clicked()
{
    emit panel_button_pressed(2);
}

void MainWindow::on_floor3Button_clicked()
{
    emit panel_button_pressed(3);
}

void MainWindow::on_floor4Button_clicked()
{
    emit panel_button_pressed(4);
}

void MainWindow::on_floor5Button_clicked()
{
    emit panel_button_pressed(5);
}

void MainWindow::on_floor6Button_clicked()
{
    emit panel_button_pressed(6);
}

void MainWindow::on_floor7Button_clicked()
{
    emit panel_button_pressed(7);
}

void MainWindow::on_floor8Button_clicked()
{
    emit panel_button_pressed(8);
}

void MainWindow::on_floor9Button_clicked()
{
    emit panel_button_pressed(9);
}

void MainWindow::on_floor10Button_clicked()
{
    emit panel_button_pressed(10);
}

void MainWindow::on_lift_move()
{
    ui->liftStoppedLabel->setText("Moving");
    ui->liftStoppedLabel->repaint();
}

void MainWindow::on_lift_stop(int floor)
{
    ui->liftStoppedLabel->setText("Stopped");
    ui->liftStoppedLabel->repaint();
    on_lift_reached_floor(floor);
}

void MainWindow::on_lift_open()
{
    ui->liftClosedLabel->setText("Opened");
    ui->liftClosedLabel->repaint();
    int t = door1_item->rect().top();
    door1_item->setRect(450-(30), t, 30, 60);
    door2_item->setRect(480+(30), t, 30, 60);
}

void MainWindow::on_lift_close()
{
    ui->liftClosedLabel->setText("Closed");
    ui->liftClosedLabel->repaint();
    int t = door1_item->rect().top();
    door1_item->setRect(450-(0), t, 30, 60);
    door2_item->setRect(480+(0), t, 30, 60);
}

void MainWindow::on_lift_opening()
{
    ui->liftClosedLabel->setText("Opening");
    ui->liftClosedLabel->repaint();
    int t = door1_item->rect().top();
    door1_item->setRect(450-(15), t, 30, 60);
    door2_item->setRect(480+(15), t, 30, 60);
}

void MainWindow::on_lift_closing()
{
    ui->liftClosedLabel->setText("Closing");
    ui->liftClosedLabel->repaint();
    int t = door1_item->rect().top();
    door1_item->setRect(450-(15), t, 30, 60);
    door2_item->setRect(480+(15), t, 30, 60);
}

void MainWindow::on_lift_reached_floor(int floor)
{
    QString str("Floor ");
    QString n(QString::number(floor));
    str.append(n);
    ui->liftFloorLabel->setText(str);
    ui->liftFloorLabel->repaint();
    lift_item->setRect(450, 560-(60*(floor-1)), 60, 60);
    door1_item->setRect(450, 560-(60*(floor-1)), 30, 60);
    door2_item->setRect(480, 560-(60*(floor-1)), 30, 60);
}
