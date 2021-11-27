/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInfo;
    QAction *actionStatistics;
    QAction *actionApp;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPack;
    QPushButton *btnUnpack;
    QListView *lvFileDir;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(598, 433);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        actionStatistics = new QAction(MainWindow);
        actionStatistics->setObjectName(QString::fromUtf8("actionStatistics"));
        actionApp = new QAction(MainWindow);
        actionApp->setObjectName(QString::fromUtf8("actionApp"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnPack = new QPushButton(groupBox);
        btnPack->setObjectName(QString::fromUtf8("btnPack"));
        QFont font;
        font.setPointSize(15);
        btnPack->setFont(font);

        verticalLayout->addWidget(btnPack);

        btnUnpack = new QPushButton(groupBox);
        btnUnpack->setObjectName(QString::fromUtf8("btnUnpack"));
        btnUnpack->setFont(font);

        verticalLayout->addWidget(btnUnpack);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        lvFileDir = new QListView(centralwidget);
        lvFileDir->setObjectName(QString::fromUtf8("lvFileDir"));
        lvFileDir->setFont(font);

        gridLayout->addWidget(lvFileDir, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 598, 21));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionApp);
        menuHelp->addAction(actionInfo);
        menuHelp->addAction(actionStatistics);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PackApp", nullptr));
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        actionStatistics->setText(QCoreApplication::translate("MainWindow", "Analytics", nullptr));
        actionApp->setText(QCoreApplication::translate("MainWindow", "Pack app", nullptr));
        groupBox->setTitle(QString());
        btnPack->setText(QCoreApplication::translate("MainWindow", "Pack", nullptr));
        btnUnpack->setText(QCoreApplication::translate("MainWindow", "Unpack", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
