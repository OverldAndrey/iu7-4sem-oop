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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
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
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *floor5Button;
    QPushButton *floor1Button;
    QPushButton *floor7Button;
    QPushButton *floor8Button;
    QPushButton *floor2Button;
    QPushButton *floor3Button;
    QPushButton *floor4Button;
    QPushButton *floor10Button;
    QPushButton *floor9Button;
    QPushButton *floor6Button;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *callEdit;
    QPushButton *callButton;
    QLabel *liftStoppedLabel;
    QLabel *liftClosedLabel;
    QLabel *liftFloorLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 960, 640));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(1020, 10, 251, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        floor5Button = new QPushButton(gridLayoutWidget);
        floor5Button->setObjectName(QStringLiteral("floor5Button"));

        gridLayout->addWidget(floor5Button, 5, 0, 1, 1);

        floor1Button = new QPushButton(gridLayoutWidget);
        floor1Button->setObjectName(QStringLiteral("floor1Button"));

        gridLayout->addWidget(floor1Button, 0, 0, 1, 1);

        floor7Button = new QPushButton(gridLayoutWidget);
        floor7Button->setObjectName(QStringLiteral("floor7Button"));

        gridLayout->addWidget(floor7Button, 2, 1, 1, 1);

        floor8Button = new QPushButton(gridLayoutWidget);
        floor8Button->setObjectName(QStringLiteral("floor8Button"));

        gridLayout->addWidget(floor8Button, 3, 1, 1, 1);

        floor2Button = new QPushButton(gridLayoutWidget);
        floor2Button->setObjectName(QStringLiteral("floor2Button"));

        gridLayout->addWidget(floor2Button, 2, 0, 1, 1);

        floor3Button = new QPushButton(gridLayoutWidget);
        floor3Button->setObjectName(QStringLiteral("floor3Button"));

        gridLayout->addWidget(floor3Button, 3, 0, 1, 1);

        floor4Button = new QPushButton(gridLayoutWidget);
        floor4Button->setObjectName(QStringLiteral("floor4Button"));

        gridLayout->addWidget(floor4Button, 4, 0, 1, 1);

        floor10Button = new QPushButton(gridLayoutWidget);
        floor10Button->setObjectName(QStringLiteral("floor10Button"));

        gridLayout->addWidget(floor10Button, 5, 1, 1, 1);

        floor9Button = new QPushButton(gridLayoutWidget);
        floor9Button->setObjectName(QStringLiteral("floor9Button"));

        gridLayout->addWidget(floor9Button, 4, 1, 1, 1);

        floor6Button = new QPushButton(gridLayoutWidget);
        floor6Button->setObjectName(QStringLiteral("floor6Button"));

        gridLayout->addWidget(floor6Button, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(1020, 240, 251, 61));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        callEdit = new QLineEdit(gridLayoutWidget_2);
        callEdit->setObjectName(QStringLiteral("callEdit"));

        gridLayout_2->addWidget(callEdit, 0, 0, 1, 1);

        callButton = new QPushButton(gridLayoutWidget_2);
        callButton->setObjectName(QStringLiteral("callButton"));

        gridLayout_2->addWidget(callButton, 0, 1, 1, 1);

        liftStoppedLabel = new QLabel(centralWidget);
        liftStoppedLabel->setObjectName(QStringLiteral("liftStoppedLabel"));
        liftStoppedLabel->setGeometry(QRect(1020, 320, 251, 31));
        liftClosedLabel = new QLabel(centralWidget);
        liftClosedLabel->setObjectName(QStringLiteral("liftClosedLabel"));
        liftClosedLabel->setGeometry(QRect(1020, 360, 251, 31));
        liftFloorLabel = new QLabel(centralWidget);
        liftFloorLabel->setObjectName(QStringLiteral("liftFloorLabel"));
        liftFloorLabel->setGeometry(QRect(1020, 400, 251, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        floor5Button->setText(QApplication::translate("MainWindow", "5", nullptr));
        floor1Button->setText(QApplication::translate("MainWindow", "1", nullptr));
        floor7Button->setText(QApplication::translate("MainWindow", "7", nullptr));
        floor8Button->setText(QApplication::translate("MainWindow", "8", nullptr));
        floor2Button->setText(QApplication::translate("MainWindow", "2", nullptr));
        floor3Button->setText(QApplication::translate("MainWindow", "3", nullptr));
        floor4Button->setText(QApplication::translate("MainWindow", "4", nullptr));
        floor10Button->setText(QApplication::translate("MainWindow", "10", nullptr));
        floor9Button->setText(QApplication::translate("MainWindow", "9", nullptr));
        floor6Button->setText(QApplication::translate("MainWindow", "6", nullptr));
        callEdit->setText(QApplication::translate("MainWindow", "1", nullptr));
        callButton->setText(QApplication::translate("MainWindow", "Call Lift", nullptr));
        liftStoppedLabel->setText(QApplication::translate("MainWindow", "stopped", nullptr));
        liftClosedLabel->setText(QApplication::translate("MainWindow", "closed", nullptr));
        liftFloorLabel->setText(QApplication::translate("MainWindow", "floor 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
