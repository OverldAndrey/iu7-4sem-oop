#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "process.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx("-?\\d{1,9}\\.?\\d{0,9} -?\\d{1,9}\\.?\\d{0,9} -?\\d{1,9}\\.?\\d{0,9}");
    QValidator *v = new QRegExpValidator(rx, this);
    ui->moveEdit->setValidator(v);
    ui->scaleEdit->setValidator(v);
    ui->rotateEdit->setValidator(v);
    ui->cameraEdit->setValidator(v);
}

MainWindow::~MainWindow()
{
    Result result = main_process({.code = finish,
                                  .transform = {.px = 0, .py = 0, .pz = 0},
                                  .fname = nullptr});
    if (result.error != success)
        ui->errorLabel->setText(show_error_message(result.error));
    else
        ui->errorLabel->setText("");
    delete ui;
}

void MainWindow::on_loadFileButton_clicked()
{
    std::string *fname = new std::string(ui->loadFileEdit->text().toStdString());
    const char * const fname_data = fname->data();
    Result result = main_process({.code = loadf,
                                  .transform = {.px = 0, .py = 0, .pz = 0},
                                  .fname = fname_data});

    if (result.error != success)
        ui->errorLabel->setText(show_error_message(result.error));
    else
    {
        ui->errorLabel->setText("");
        ui->canvas->setPixmap(*((QPixmap*)result.m));
    }

    delete fname;
    delete (QPixmap*)(result.m);
}

void MainWindow::on_saveFileButton_clicked()
{
    std::string *fname = new std::string(ui->saveFileEdit->text().toStdString());
    const char * const fname_data = fname->data();
    Result result = main_process({.code = savef,
                                  .transform = {.px = 0, .py = 0, .pz = 0},
                                  .fname = fname_data});

    if (result.error != success)
        ui->canvas->setText(show_error_message(result.error));
    else
        ui->errorLabel->setText("");
    delete fname;
}

void MainWindow::on_moveButton_clicked()
{
    QStringList inp = ui->moveEdit->text().split(' ');
    Result result = main_process({.code = movef,
                                  .transform = {.px = inp[0].toFloat(), .py = inp[1].toFloat(), .pz = inp[2].toFloat()},
                                  .fname = nullptr});

    if (result.error != success)
        ui->errorLabel->setText(show_error_message(result.error));
    else
    {
        ui->errorLabel->setText("");
        ui->canvas->setPixmap(*((QPixmap*)result.m));
    }

    delete (QPixmap*)(result.m);
}

void MainWindow::on_scaleButton_clicked()
{
    QStringList inp = ui->scaleEdit->text().split(' ');
    Result result = main_process({.code = scalef,
                                  .transform = {.px = inp[0].toFloat(), .py = inp[1].toFloat(), .pz = inp[2].toFloat()},
                                  .fname = nullptr});

    if (result.error != success)
        ui->errorLabel->setText(show_error_message(result.error));
    else
    {
        ui->errorLabel->setText("");
        ui->canvas->setPixmap(*((QPixmap*)result.m));
    }

    delete (QPixmap*)(result.m);
}

void MainWindow::on_rotateButton_clicked()
{
    QStringList inp = ui->rotateEdit->text().split(' ');
    Result result = main_process({.code = rotatef,
                                  .transform = {.px = inp[0].toFloat(), .py = inp[1].toFloat(), .pz = inp[2].toFloat()},
                                  .fname = nullptr});

    if (result.error != success)
        ui->errorLabel->setText(show_error_message(result.error));
    else
    {
        ui->errorLabel->setText("");
        ui->canvas->setPixmap(*((QPixmap*)result.m));
    }

    delete (QPixmap*)(result.m);
}

void MainWindow::on_cameraButton_clicked()
{
    QStringList inp = ui->cameraEdit->text().split(' ');
    Result result = main_process({.code = rotatecam,
                                  .transform = {.px = inp[0].toFloat(), .py = inp[1].toFloat(), .pz = inp[2].toFloat()},
                                  .fname = nullptr});

    if (result.error != success)
        ui->errorLabel->setText(show_error_message(result.error));
    else
    {
        ui->errorLabel->setText("");
        ui->canvas->setPixmap(*((QPixmap*)result.m));
    }

    delete (QPixmap*)(result.m);
}

void MainWindow::on_drawButton_clicked()
{

}
