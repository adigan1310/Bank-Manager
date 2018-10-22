#ifndef DIALOG7_H
#define DIALOG7_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog7;
}

class Dialog7 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog7(QWidget *parent = 0);
    ~Dialog7();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Dialog7 *ui;
};

#endif // DIALOG7_H
