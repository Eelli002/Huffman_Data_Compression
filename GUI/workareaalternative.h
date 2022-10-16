#ifndef WORKAREAALTERNATIVE_H
#define WORKAREAALTERNATIVE_H

#include <QMainWindow>

namespace Ui {
class workareaalternative;
}

class workareaalternative : public QMainWindow
{
    Q_OBJECT

public:
    explicit workareaalternative(QWidget *parent = nullptr);
    ~workareaalternative();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionEncrypt_triggered();

private:
    Ui::workareaalternative *ui;
    QString filepath;
};

#endif // WORKAREAALTERNATIVE_H
