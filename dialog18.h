#ifndef DIALOG18_H
#define DIALOG18_H
#include "dialog1.h"
#include <QDialog>

namespace Ui {
class Dialog18;
}

class Dialog18 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog18(QWidget *parent = 0);
    ~Dialog18();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog18 *ui;
};

#endif // DIALOG18_H
