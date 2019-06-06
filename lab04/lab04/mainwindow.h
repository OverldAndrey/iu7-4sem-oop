#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainprocess.h"

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
    void on_loadFileButton_clicked();

    void on_saveFileButton_clicked();

    void on_moveButton_clicked();

    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

    void on_cameraButton_clicked();

    void on_drawButton_clicked();

private:
    Ui::MainWindow *ui;
    MainProcess mp;
};

#endif // MAINWINDOW_H
