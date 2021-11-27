/********************************************************************************
** Form generated from reading UI file 'statisticswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSWINDOW_H
#define UI_STATISTICSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *graphLayout;

    void setupUi(QWidget *StatisticsWindow)
    {
        if (StatisticsWindow->objectName().isEmpty())
            StatisticsWindow->setObjectName(QString::fromUtf8("StatisticsWindow"));
        StatisticsWindow->resize(594, 475);
        horizontalLayout = new QHBoxLayout(StatisticsWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphLayout = new QGridLayout();
        graphLayout->setObjectName(QString::fromUtf8("graphLayout"));

        horizontalLayout->addLayout(graphLayout);


        retranslateUi(StatisticsWindow);

        QMetaObject::connectSlotsByName(StatisticsWindow);
    } // setupUi

    void retranslateUi(QWidget *StatisticsWindow)
    {
        StatisticsWindow->setWindowTitle(QCoreApplication::translate("StatisticsWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsWindow: public Ui_StatisticsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSWINDOW_H
