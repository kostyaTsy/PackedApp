#ifndef PACKUNPACKWINDOW_H
#define PACKUNPACKWINDOW_H

#include <QWidget>
#include <string>
//using namespace std;

namespace Ui {
class PackUnpackWindow;
}

class PackUnpackWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PackUnpackWindow(QWidget *parent = nullptr);
    ~PackUnpackWindow();
    std::string filePath;
    std::string savePath;
    bool IsPack;

private slots:
    void on_PackUnpackWindow_windowTitleChanged(const QString &title);

    void on_btnAction_clicked();

    void on_btnChoosePath_clicked();

private:
    Ui::PackUnpackWindow *ui;
};

#endif // PACKUNPACKWINDOW_H
