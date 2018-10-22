#ifndef DIALOG4_H
#define DIALOG4_H
#include "dialog6.h"
#include "dialog10.h"
#include "dialog12.h"
#include <QDialog>

namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = 0);
    ~Dialog4();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_4_clicked();

private:
    Ui::Dialog4 *ui;
};

#endif // DIALOG4_H
