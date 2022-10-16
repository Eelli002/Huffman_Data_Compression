#ifndef WORKAREA_H
#define WORKAREA_H

#include <QMainWindow>

namespace Ui {
class WorkArea;
}

class WorkArea : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkArea(QWidget *parent = nullptr);
    ~WorkArea();

private slots:
    void on_fileopenbutton_clicked();

    void on_encryptbutton_clicked();

    void on_saveasbutton_clicked();

private:
    Ui::WorkArea *ui;
};

#endif // WORKAREA_H
