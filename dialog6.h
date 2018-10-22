#ifndef DIALOG6_H
#define DIALOG6_H
#include "dialog1.h"
#include <QDialog>

namespace Ui {
class Dialog6;
}

class Dialog6 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog6(QWidget *parent = 0);
    ~Dialog6();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog6 *ui;
};

#endif // DIALOG6_H
