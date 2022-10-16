#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workarea.h"
#include "workareaalternative.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
//    WorkArea *wa = new WorkArea(this);
//    wa->show();
    workareaalternative *waa = new workareaalternative(this);
    waa->show();
}
