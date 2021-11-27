#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lvFileDir_doubleClicked(const QModelIndex &index);
    void on_btnPack_clicked();

    void on_actionInfo_triggered();

    void on_actionApp_triggered();

    void on_actionStatistics_triggered();

private:
    Ui::MainWindow *ui;
    // variable of class QFileSystemModel to create a file system
    QFileSystemModel *model;
};
#endif // MAINWINDOW_H
