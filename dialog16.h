#ifndef DIALOG16_H
#define DIALOG16_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog16;
}

class Dialog16 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog16(QWidget *parent = 0);
    ~Dialog16();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_8_clicked();

    void on_commandLinkButton_5_clicked();

private:
    Ui::Dialog16 *ui;
    MainWindow *in;
};

#endif // DIALOG16_H
