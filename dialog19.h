#ifndef DIALOG19_H
#define DIALOG19_H
#include "dialog1.h"
#include <QDialog>

namespace Ui {
class Dialog19;
}

class Dialog19 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog19(QWidget *parent = 0);
    ~Dialog19();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog19 *ui;
};

#endif // DIALOG19_H
