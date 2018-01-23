#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QKeySequence>
#include <QEvent>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDesktopServices>

bool configMode=false;
bool top_route=false;
bool left_route=false;
bool right_route=false;
bool bottom_route=false;
QString topProgramRoute="null";
QString bottomProgramRoute="null";
QString leftProgramRoute="null";
QString rightProgramRoute="null";
QFile file("file.txt");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: lightgray;");
    ui->config_label->setStyleSheet("color:black;");
    ui->config_label->hide();
    ui->accept->hide();
    config_dialog= new Config(this);

    //File reading

    if(!file.exists()){
        qInfo() << file.fileName() <<"does not exist";
    }
    if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream txtStream(&file);
        qInfo("reading...");
        txtStream.seek(0);
        int cont=0;
        while(!txtStream.atEnd()){
            if(cont==0) topProgramRoute=txtStream.readLine();
            if(cont==1) bottomProgramRoute=txtStream.readLine();
            if(cont==2) leftProgramRoute=txtStream.readLine();
            if(cont==3) rightProgramRoute=txtStream.readLine();
            cont++;
        }
        file.close();
    }
    else{
        qInfo("Could not open the file");
        return;
    }
    //Rutes



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_keySequenceEdit_keySequenceChanged(const QKeySequence &keySequence)
{
    if(keySequence==QKeySequence("Ctrl+Shift+Up")){
        qInfo("ejecutando...");
        QDesktopServices::openUrl(QUrl("file:///"+topProgramRoute, QUrl::TolerantMode));
    }
    if(keySequence==QKeySequence("Ctrl+Shift+Left")){
        qInfo("ejecutando...");
        QDesktopServices::openUrl(QUrl("file:///"+leftProgramRoute, QUrl::TolerantMode));
    }
    if(keySequence==QKeySequence("Ctrl+Shift+Right")){
        qInfo("ejecutando...");
        QDesktopServices::openUrl(QUrl("file:///"+rightProgramRoute, QUrl::TolerantMode));
    }
    if(keySequence==QKeySequence("Ctrl+Shift+Down")){
        qInfo("ejecutando...");
        QDesktopServices::openUrl(QUrl("file:///"+bottomProgramRoute, QUrl::TolerantMode));
    }
}

void MainWindow::on_config_clicked()
{
    if(configMode){
        ui->config_label->hide();
        ui->keySequenceEdit->show();
        this->setStyleSheet("background-color: lightgray;");
        ui->top->setStyleSheet("background-color: darkgray;border: 1px solid darkgray");
        ui->left->setStyleSheet("background-color: darkgray;border: 1px solid darkgray");
        ui->right->setStyleSheet("background-color: darkgray;border: 1px solid darkgray");
        ui->bottom->setStyleSheet("background-color: darkgray;border: 1px solid darkgray");
        configMode=false;
    }
    else{
        ui->config_label->show();
        ui->keySequenceEdit->hide();
        this->setStyleSheet("background-color: gray;");
        ui->top->setStyleSheet("background-color: lightgray;border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.017, stop:0 rgba(255, 255, 255, 255),"
                               " stop:0.495 rgba(255, 255, 255, 255), stop:0.505 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));");
        ui->left->setStyleSheet("background-color: lightgray;border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.017, stop:0 rgba(255, 255, 255, 255),"
                               " stop:0.495 rgba(255, 255, 255, 255), stop:0.505 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));");
        ui->right->setStyleSheet("background-color: lightgray;border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.017, stop:0 rgba(255, 255, 255, 255),"
                               " stop:0.495 rgba(255, 255, 255, 255), stop:0.505 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));");
        ui->bottom->setStyleSheet("background-color: lightgray;border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.017, stop:0 rgba(255, 255, 255, 255),"
                               " stop:0.495 rgba(255, 255, 255, 255), stop:0.505 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));");
        configMode=true;
    }
}

void MainWindow::on_accept_clicked()
{
    ui->config_label->hide();
    ui->accept->hide();
    ui->keySequenceEdit->show();
    this->setStyleSheet("background-color: lightgray;");
    configMode=false;
}

void MainWindow::on_top_clicked()
{
    if(configMode){
            topProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");
            if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream txtStream(&file);
                qInfo("writing...");
                txtStream << topProgramRoute << "\n";
                txtStream << bottomProgramRoute << "\n";
                txtStream << leftProgramRoute << "\n";
                txtStream << rightProgramRoute << "\n";

                txtStream.seek(0);
                int cont=0;
                while(!txtStream.atEnd()){
                    qInfo() << txtStream.readLine();
                }
                file.close();
           }
    }
}

void MainWindow::on_left_clicked()
{
    if(configMode){
        leftProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");
        if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream txtStream(&file);
            qInfo("writing...");
            txtStream << topProgramRoute << "\n";
            txtStream << bottomProgramRoute << "\n";
            txtStream << leftProgramRoute << "\n";
            txtStream << rightProgramRoute << "\n";

            txtStream.seek(0);
            int cont=0;
            while(!txtStream.atEnd()){
                qInfo() << txtStream.readLine();
            }
            file.close();
       }
    }
}

void MainWindow::on_right_clicked()
{
    if(configMode){
        rightProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");
        if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream txtStream(&file);
            qInfo("writing...");
            txtStream << topProgramRoute << "\n";
            txtStream << bottomProgramRoute << "\n";
            txtStream << leftProgramRoute << "\n";
            txtStream << rightProgramRoute << "\n";

            txtStream.seek(0);
            int cont=0;
            while(!txtStream.atEnd()){
                qInfo() << txtStream.readLine();
            }
            file.close();
       }
    }
}

void MainWindow::on_bottom_clicked()
{
    if(configMode){
        bottomProgramRoute = QFileDialog::getOpenFileName(this, "Open a file", "C://");
        if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream txtStream(&file);
            qInfo("writing...");
            txtStream << topProgramRoute << "\n";
            txtStream << bottomProgramRoute << "\n";
            txtStream << leftProgramRoute << "\n";
            txtStream << rightProgramRoute << "\n";

            txtStream.seek(0);
            int cont=0;
            while(!txtStream.atEnd()){
                qInfo() << txtStream.readLine();
            }
            file.close();
       }
    }
}
