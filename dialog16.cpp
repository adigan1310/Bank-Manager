#include "dialog16.h"
#include "ui_dialog16.h"
#include "dialog3.h"
#include "dialog13.h"
#include "dialog17.h"
#include "dialog21.h"

Dialog16::Dialog16(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog16)
{
    ui->setupUi(this);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog16::~Dialog16()
{
    delete ui;
}

void Dialog16::on_pushButton_clicked()
{
    in = new MainWindow();
    in->show();
    this->close();
}

void Dialog16::on_commandLinkButton_4_clicked()
{
    Dialog3 dialog3;
    dialog3.setModal(true);
    dialog3.exec();
}

void Dialog16::on_commandLinkButton_8_clicked()
{
    Dialog13 dialog13;
    dialog13.setModal(true);
    dialog13.exec();
}

void Dialog16::on_commandLinkButton_5_clicked()
{
    this->close();
    Dialog21  dialog17;
    dialog17.setModal(true);
    dialog17.exec();
}
