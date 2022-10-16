#include "workarea.h"
#include "ui_workarea.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

WorkArea::WorkArea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkArea)
{
    ui->setupUi(this);
}

WorkArea::~WorkArea()
{
    delete ui;
}

void WorkArea::on_fileopenbutton_clicked()
{
    QString filter = "All Files (*.*) ;; Text Files (*.txt)";
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), filter);
    QFile file(filename);

    //check if file is open 2 params - type of file and what to do with it readonly/writeonly | we want to make text file
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Umm", "No file was opened");
    }
    else{

        QTextStream in(&file);
        QString text = in.readAll();
        ui->readwindow->setPlainText(text);

        //shows current file's path on label
        ui->currentreadfile->setText(filename);
    }

    file.close();
}

//calls encryption function and outputs it to encryption window
void WorkArea::on_encryptbutton_clicked()
{
    //calls the encryption function


}

void WorkArea::on_saveasbutton_clicked()
{
    QString filename = ui->outfilename->text();
    QFile file(filename);

    file.open(QFile::WriteOnly | QFile::Text);

    QTextStream out(&file);
    QString text = ui->encryptionwindow->toPlainText();
    out << text;
    file.flush();
    file.close();
}
