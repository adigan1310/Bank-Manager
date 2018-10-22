#ifndef DIALOG21_H
#define DIALOG21_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog21;
}

class Dialog21 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog21(QWidget *parent = 0);
    ~Dialog21();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog21 *ui;
    MainWindow *in;
};

#endif // DIALOG21_H
