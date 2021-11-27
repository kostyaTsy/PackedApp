/********************************************************************************
** Form generated from reading UI file 'packunpackwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKUNPACKWINDOW_H
#define UI_PACKUNPACKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackUnpackWindow
{
public:
    QComboBox *cbPackAlgo;
    QLineEdit *lePath;
    QPushButton *btnAction;
    QPushButton *btnChoosePath;

    void setupUi(QWidget *PackUnpackWindow)
    {
        if (PackUnpackWindow->objectName().isEmpty())
            PackUnpackWindow->setObjectName(QString::fromUtf8("PackUnpackWindow"));
        PackUnpackWindow->resize(400, 300);
        PackUnpackWindow->setMinimumSize(QSize(400, 300));
        PackUnpackWindow->setMaximumSize(QSize(400, 300));
        cbPackAlgo = new QComboBox(PackUnpackWindow);
        cbPackAlgo->addItem(QString());
        cbPackAlgo->addItem(QString());
        cbPackAlgo->addItem(QString());
        cbPackAlgo->setObjectName(QString::fromUtf8("cbPackAlgo"));
        cbPackAlgo->setGeometry(QRect(150, 30, 101, 24));
        lePath = new QLineEdit(PackUnpackWindow);
        lePath->setObjectName(QString::fromUtf8("lePath"));
        lePath->setGeometry(QRect(10, 130, 371, 24));
        lePath->setReadOnly(true);
        btnAction = new QPushButton(PackUnpackWindow);
        btnAction->setObjectName(QString::fromUtf8("btnAction"));
        btnAction->setGeometry(QRect(160, 220, 80, 31));
        btnChoosePath = new QPushButton(PackUnpackWindow);
        btnChoosePath->setObjectName(QString::fromUtf8("btnChoosePath"));
        btnChoosePath->setGeometry(QRect(300, 90, 80, 31));

        retranslateUi(PackUnpackWindow);

        QMetaObject::connectSlotsByName(PackUnpackWindow);
    } // setupUi

    void retranslateUi(QWidget *PackUnpackWindow)
    {
        PackUnpackWindow->setWindowTitle(QCoreApplication::translate("PackUnpackWindow", "Form", nullptr));
        cbPackAlgo->setItemText(0, QCoreApplication::translate("PackUnpackWindow", "RLE", nullptr));
        cbPackAlgo->setItemText(1, QCoreApplication::translate("PackUnpackWindow", "LZ77", nullptr));
        cbPackAlgo->setItemText(2, QCoreApplication::translate("PackUnpackWindow", "Huffman", nullptr));

        lePath->setInputMask(QString());
        lePath->setText(QString());
        lePath->setPlaceholderText(QCoreApplication::translate("PackUnpackWindow", "Choose path to save...", nullptr));
        btnAction->setText(QCoreApplication::translate("PackUnpackWindow", "PushButton", nullptr));
        btnChoosePath->setText(QCoreApplication::translate("PackUnpackWindow", "Choose...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackUnpackWindow: public Ui_PackUnpackWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKUNPACKWINDOW_H
