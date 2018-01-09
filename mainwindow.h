#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "config.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_keySequenceEdit_keySequenceChanged(const QKeySequence &keySequence);

    void on_menu_clicked();

private:
    Ui::MainWindow *ui;
    Config *config_dialog;
};

#endif // MAINWINDOW_H
