#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include "process.h"
#include "loadcommand.h"
#include "savecommand.h"
#include "drawcommand.h"
#include "movecommand.h"
#include "scalecommand.h"
#include "rotatecommand.h"


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

    this->on_drawButton_clicked();
}

MainWindow::~MainWindow()
{
//    Result result = main_process({.code = finish,
//                                  .transform = {.px = 0, .py = 0, .pz = 0},
//                                  .fname = nullptr});
//    if (result.error != success)
//        ui->errorLabel->setText(show_error_message(result.error));
//    else
//        ui->errorLabel->setText("");
//    delete ui;
}

void MainWindow::on_loadFileButton_clicked()
{
    std::string fname(ui->loadFileEdit->text().toStdString());

    try
    {
        auto com = LoadCommand(fname.c_str());
        mp.process(com);

        this->on_drawButton_clicked();
    }
    catch (std::exception e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void MainWindow::on_saveFileButton_clicked()
{
    std::string fname(ui->saveFileEdit->text().toStdString());

    try
    {
        auto com = SaveCommand(fname.c_str());
        mp.process(com);
    }
    catch (std::exception e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void MainWindow::on_moveButton_clicked()
{
    QStringList inp = ui->moveEdit->text().split(' ');

    try
    {
        auto com = MoveCommand(inp[0].toDouble(), inp[1].toDouble(), inp[2].toDouble(), "");
        mp.process(com);

        this->on_drawButton_clicked();
    }
    catch (std::exception e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void MainWindow::on_scaleButton_clicked()
{
    QStringList inp = ui->scaleEdit->text().split(' ');

    try
    {
        auto com = ScaleCommand(inp[0].toDouble(), inp[1].toDouble(), inp[2].toDouble(), "");
        mp.process(com);

        this->on_drawButton_clicked();
    }
    catch (std::exception e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void MainWindow::on_rotateButton_clicked()
{
    QStringList inp = ui->rotateEdit->text().split(' ');

    try
    {
        auto com = RotateCommand(inp[0].toDouble(), inp[1].toDouble(), inp[2].toDouble(), "");
        mp.process(com);

        this->on_drawButton_clicked();
    }
    catch (std::exception e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void MainWindow::on_cameraButton_clicked()
{
    QStringList inp = ui->cameraEdit->text().split(' ');

    try
    {
        auto com = RotateCommand(inp[0].toDouble(), inp[1].toDouble(), inp[2].toDouble(), "0");
        mp.process(com);

        this->on_drawButton_clicked();
    }
    catch (std::exception e)
    {
        ui->errorLabel->setText(e.what());
    }
}

void MainWindow::on_drawButton_clicked()
{
    try
    {
        auto com = DrawCommand();
        auto data = mp.process(com);

        ui->errorLabel->setText("");
        ui->canvas->setPixmap(*(static_cast<DrawResult*>(data.get())->get_data(0)));
    }
    catch (std::exception e)
    {
        ui->errorLabel->setText(e.what());
    }
}
