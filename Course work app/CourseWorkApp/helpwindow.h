#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

private slots:
    void on_HelpWindow_windowTitleChanged(const QString &title);

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
