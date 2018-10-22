#ifndef DIALOG14_H
#define DIALOG14_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog14;
}

class Dialog14 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog14(QWidget *parent = 0);
    ~Dialog14();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_3_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_6_clicked();

private:
    Ui::Dialog14 *ui;
    MainWindow *in;
};

#endif // DIALOG14_H
