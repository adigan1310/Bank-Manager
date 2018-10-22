#ifndef DIALOG_H
#define DIALOG_H
#include "mainwindow.h"
#include <QDialog>
#include "dialog1.h"
#include "dialog3.h"
#include "dialog8.h"
#include "dialog9.h"
#include "dialog4.h"
#include "dialog11.h"
#include "dialog12.h"
#include "dialog13.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_8_clicked();

    void on_commandLinkButton_6_clicked();

    void on_commandLinkButton_9_clicked();

private:
    Ui::Dialog *ui;
    MainWindow *in;
};

#endif // DIALOG_H
