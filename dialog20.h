#ifndef DIALOG20_H
#define DIALOG20_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog20;
}

class Dialog20 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog20(QWidget *parent = 0);
    ~Dialog20();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog20 *ui;
    MainWindow *in;
};

#endif // DIALOG20_H
