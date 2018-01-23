#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>

namespace Ui {
class Config;
}

class Config : public QDialog
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = 0);
    ~Config();

private slots:
    void on_top_clicked();

    void on_left_clicked();

    void on_bottom_clicked();

    void on_right_clicked();

private:
    Ui::Config *ui;
};

#endif // CONFIG_H
