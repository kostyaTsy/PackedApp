#include "helpwindow.h"
#include "ui_helpwindow.h"
#include "string"
#include "QFile"

#include <fstream>

HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);

}

// Reading text file
QString ReadTextFile(QString filePath) {
    QFile f(filePath);

    if (f.open(QIODevice::ReadOnly)) {
        QTextStream in(&f);
        QString text = in.readAll();

        return text;
    }

    return "";

}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::on_HelpWindow_windowTitleChanged(const QString &title)
{
    if (title == "Info") {
        ui->textEdit->setText(ReadTextFile("Info.txt"));
        this->setFixedSize(500, 400);
        this->setMaximumSize(2000, 2000);
    }
}

