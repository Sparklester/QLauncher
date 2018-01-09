#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QKeySequence>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    config_dialog= new Config(this);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_keySequenceEdit_keySequenceChanged(const QKeySequence &keySequence)
{
    if(keySequence==QKeySequence("Ctrl+Shift+Up")){
        qInfo("funciona");
        system("start chrome.exe");
    }
    if(keySequence==QKeySequence("Ctrl+Shift+Left")){
        qInfo("funciona");
        system("start chrome.exe");
    }
    if(keySequence==QKeySequence("Ctrl+Shift+Right")){
        qInfo("funciona");
        system("start chrome.exe");
    }
    if(keySequence==QKeySequence("Ctrl+Shift+Down")){
        qInfo("funciona");
        system("start chrome.exe");
    }
}

void MainWindow::on_menu_clicked()
{
    config_dialog->show();
}
