#ifndef DIALOG5_H
#define DIALOG5_H
#include "dialog1.h"
#include <QDialog>

namespace Ui {
class Dialog5;
}

class Dialog5 : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog5(QWidget *parent = 0);
    ~Dialog5();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_clicked();

private:
    Ui::Dialog5 *ui;
};

#endif // DIALOG5_H
