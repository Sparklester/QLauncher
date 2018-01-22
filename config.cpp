#include "config.h"
#include "ui_config.h"
#include <QFileDialog>
#include <QString>

Config::Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
}

Config::~Config()
{

    delete ui;
}


void Config::on_top_clicked()
{
    QString topProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");
}

void Config::on_left_clicked()
{
    QString leftProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");
}

void Config::on_bottom_clicked()
{
    QString bottomProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");

}

void Config::on_right_clicked()
{
    QString rightProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");

}
