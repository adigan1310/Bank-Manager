#ifndef DIALOG11_H
#define DIALOG11_H

#include <QDialog>
#include "dialog1.h"
namespace Ui {
class Dialog11;
}

class Dialog11 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog11(QWidget *parent = 0);
    ~Dialog11();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog11 *ui;
};

#endif // DIALOG11_H
