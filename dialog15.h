#ifndef DIALOG15_H
#define DIALOG15_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog15;
}

class Dialog15 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog15(QWidget *parent = 0);
    ~Dialog15();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_6_clicked();

    void on_commandLinkButton_9_clicked();

    void on_commandLinkButton_8_clicked();

private:
    Ui::Dialog15 *ui;
    MainWindow *in;
};

#endif // DIALOG15_H
