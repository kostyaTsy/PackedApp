#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "packunpackwindow.h"
#include "helpwindow.h"
#include "statisticswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    model->setFilter(QDir::QDir::AllEntries);
    model->setRootPath("");
    ui->lvFileDir->setModel(model);

    connect(ui->btnUnpack, SIGNAL(clicked()), this, SLOT(on_btnPack_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Going throw the files in the file manager
void MainWindow::on_lvFileDir_doubleClicked(const QModelIndex &index)
{
    QListView *listView = (QListView*)sender();
    QFileInfo fileInfo = model->fileInfo(index);
    if (fileInfo.fileName() == "..") {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView->setRootIndex(model->index(dir.absolutePath()));
    }
    else if (fileInfo.fileName() == ".") {
        listView->setRootIndex(model->index(""));
    }
    else if (fileInfo.isDir()) {
        listView->setRootIndex(index);
    }
}

// Action on btnPack clicked
void MainWindow::on_btnPack_clicked()
{
    // Finding the path of current file
    QModelIndex ind = ui->lvFileDir->currentIndex();
    QFileInfo fileInfo = model->fileInfo(ind);
    QString filePath = fileInfo.filePath();

    // Creating new window
    PackUnpackWindow *packUnpackWin = new PackUnpackWindow;
    packUnpackWin->filePath = filePath.toStdString();

    if (sender() == ui->btnPack) {
        packUnpackWin->setWindowTitle("Pack file");
    }
    else if (sender() == ui->btnUnpack) {
        packUnpackWin->setWindowTitle("Unpack file");
    }


    packUnpackWin->show();
}

void MainWindow::on_actionInfo_triggered()
{
    HelpWindow *helpWindow = new HelpWindow;
    helpWindow->setWindowTitle(ui->actionInfo->text());

    helpWindow->show();
}


void MainWindow::on_actionApp_triggered()
{
    HelpWindow *helpWindow = new HelpWindow;
    helpWindow->setWindowTitle(ui->actionApp->text());

    helpWindow->show();
}


void MainWindow::on_actionStatistics_triggered()
{
    StatisticsWindow *stWindow = new StatisticsWindow;
    stWindow->setWindowTitle(ui->actionStatistics->text());

    stWindow->show();
}

