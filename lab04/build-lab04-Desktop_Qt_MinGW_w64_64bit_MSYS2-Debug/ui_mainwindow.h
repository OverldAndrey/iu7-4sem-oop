/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *canvas;
    QPushButton *rotateButton;
    QPushButton *loadFileButton;
    QLineEdit *loadFileEdit;
    QPushButton *scaleButton;
    QLineEdit *rotateEdit;
    QPushButton *moveButton;
    QLineEdit *saveFileEdit;
    QLineEdit *moveEdit;
    QPushButton *saveFileButton;
    QLineEdit *scaleEdit;
    QPushButton *cameraButton;
    QLineEdit *cameraEdit;
    QLabel *errorLabel;
    QPushButton *drawButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        canvas = new QLabel(centralWidget);
        canvas->setObjectName(QStringLiteral("canvas"));
        canvas->setGeometry(QRect(10, 10, 1600, 900));
        rotateButton = new QPushButton(centralWidget);
        rotateButton->setObjectName(QStringLiteral("rotateButton"));
        rotateButton->setGeometry(QRect(1789, 190, 121, 31));
        loadFileButton = new QPushButton(centralWidget);
        loadFileButton->setObjectName(QStringLiteral("loadFileButton"));
        loadFileButton->setGeometry(QRect(1789, 10, 121, 31));
        loadFileEdit = new QLineEdit(centralWidget);
        loadFileEdit->setObjectName(QStringLiteral("loadFileEdit"));
        loadFileEdit->setGeometry(QRect(1660, 10, 121, 31));
        scaleButton = new QPushButton(centralWidget);
        scaleButton->setObjectName(QStringLiteral("scaleButton"));
        scaleButton->setGeometry(QRect(1789, 150, 121, 31));
        rotateEdit = new QLineEdit(centralWidget);
        rotateEdit->setObjectName(QStringLiteral("rotateEdit"));
        rotateEdit->setGeometry(QRect(1660, 190, 121, 31));
        moveButton = new QPushButton(centralWidget);
        moveButton->setObjectName(QStringLiteral("moveButton"));
        moveButton->setGeometry(QRect(1789, 110, 121, 31));
        saveFileEdit = new QLineEdit(centralWidget);
        saveFileEdit->setObjectName(QStringLiteral("saveFileEdit"));
        saveFileEdit->setGeometry(QRect(1660, 50, 121, 31));
        moveEdit = new QLineEdit(centralWidget);
        moveEdit->setObjectName(QStringLiteral("moveEdit"));
        moveEdit->setGeometry(QRect(1660, 110, 121, 31));
        saveFileButton = new QPushButton(centralWidget);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(1789, 50, 121, 31));
        scaleEdit = new QLineEdit(centralWidget);
        scaleEdit->setObjectName(QStringLiteral("scaleEdit"));
        scaleEdit->setGeometry(QRect(1660, 150, 121, 31));
        cameraButton = new QPushButton(centralWidget);
        cameraButton->setObjectName(QStringLiteral("cameraButton"));
        cameraButton->setGeometry(QRect(1789, 250, 121, 31));
        cameraEdit = new QLineEdit(centralWidget);
        cameraEdit->setObjectName(QStringLiteral("cameraEdit"));
        cameraEdit->setGeometry(QRect(1660, 250, 121, 31));
        errorLabel = new QLabel(centralWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(1660, 300, 251, 321));
        drawButton = new QPushButton(centralWidget);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setGeometry(QRect(1660, 310, 251, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab01", nullptr));
        canvas->setText(QApplication::translate("MainWindow", "Please choose file", nullptr));
        rotateButton->setText(QApplication::translate("MainWindow", "Rotate", nullptr));
        loadFileButton->setText(QApplication::translate("MainWindow", "Load", nullptr));
        loadFileEdit->setText(QApplication::translate("MainWindow", "tests.txt", nullptr));
        scaleButton->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        rotateEdit->setInputMask(QString());
        rotateEdit->setText(QApplication::translate("MainWindow", "0.1 0.1 0.1", nullptr));
        moveButton->setText(QApplication::translate("MainWindow", "Move", nullptr));
        saveFileEdit->setText(QApplication::translate("MainWindow", "res.txt", nullptr));
        moveEdit->setInputMask(QString());
        moveEdit->setText(QApplication::translate("MainWindow", "10 0 0", nullptr));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        scaleEdit->setInputMask(QString());
        scaleEdit->setText(QApplication::translate("MainWindow", "2 2 2", nullptr));
        cameraButton->setText(QApplication::translate("MainWindow", "Turn camera", nullptr));
        cameraEdit->setText(QApplication::translate("MainWindow", "0.1 0.1 0.1", nullptr));
        errorLabel->setText(QString());
        drawButton->setText(QApplication::translate("MainWindow", "Draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
