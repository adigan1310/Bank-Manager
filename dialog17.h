#ifndef DIALOG17_H
#define DIALOG17_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog17;
}

class Dialog17 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog17(QWidget *parent = 0);
    ~Dialog17();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog17 *ui;
    MainWindow *in;
};

#endif // DIALOG17_H
