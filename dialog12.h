#ifndef DIALOG12_H
#define DIALOG12_H

#include <QDialog>

namespace Ui {
class Dialog12;
}

class Dialog12 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog12(QWidget *parent = 0);
    ~Dialog12();

private slots:
    void on_radioButton_clicked();
    
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_2_clicked();

    void writefile();

private:
    Ui::Dialog12 *ui;
};

#endif // DIALOG12_H
