#include "workareaalternative.h"
#include "ui_workareaalternative.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

workareaalternative::workareaalternative(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::workareaalternative)
{
    ui->setupUi(this);
}

workareaalternative::~workareaalternative()
{
    delete ui;
}

void workareaalternative::on_actionNew_triggered()
{
    filepath = "";
    ui->maintextarea->setText("");
}

void workareaalternative::on_actionOpen_triggered()
{
    QString filter = "All Files (*.*) ;; Text Files (*.txt)";
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), filter);
    QFile file(filename);
    filepath = filename;

    //check if file is open 2 params - type of file and what to do with it readonly/writeonly | we want to make text file
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "No file was opened");
    }
    else{
        QTextStream in(&file);
        QString text = in.readAll();
        ui->maintextarea->setPlainText(text);
    }

    file.close();
}

void workareaalternative::on_actionSave_triggered()
{
    QFile file(filepath);

    file.open(QFile::WriteOnly | QFile::Text);

    QTextStream out(&file);
    QString text = ui->maintextarea->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void workareaalternative::on_actionSave_As_triggered()
{
    QString filter = "Text File (*.txt)";
    QString filename = QFileDialog::getSaveFileName(this, "Open a file", QDir::currentPath(), filter);
    QFile file(filename);

    filepath = filename;

    file.open(QFile::WriteOnly | QFile::Text);

    QTextStream out(&file);
    QString text = ui->maintextarea->toPlainText();
    out << text;
    file.flush();
    file.close();
}

//for undoing a compression
void workareaalternative::on_actionUndo_triggered()
{

}

//since theres an undo might as well add a redo
void workareaalternative::on_actionRedo_triggered()
{

}

//do some encryption and put it to right text
void workareaalternative::on_actionEncrypt_triggered()
{
    ui->encryptedarea->setPlainText("Some Random Encrypted text");
    ui->keylabel->setText("somerandomkey");
}
