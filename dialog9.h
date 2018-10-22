#ifndef DIALOG9_H
#define DIALOG9_H
#include "dialog1.h"
#include <QDialog>

namespace Ui {
class Dialog9;
}

class Dialog9 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog9(QWidget *parent = 0);
    ~Dialog9();

private slots:
    void on_checkBox_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog9 *ui;
};

#endif // DIALOG9_H
