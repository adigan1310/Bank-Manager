#include "dialog14.h"
#include "ui_dialog14.h"
#include "dialog1.h"
#include "dialog9.h"
#include "dialog3.h"
#include "dialog8.h"
#include "dialog4.h"
#include "dialog17.h"

Dialog14::Dialog14(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog14)
{
    ui->setupUi(this);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog14::~Dialog14()
{
    delete ui;
}

void Dialog14::on_commandLinkButton_clicked()
{
    Dialog1 dialog1;
    dialog1.setModal(true);
    dialog1.exec();
}

void Dialog14::on_commandLinkButton_2_clicked()
{
    Dialog9 dialog9;
    dialog9.setModal(true);
    dialog9.exec();
}

void Dialog14::on_commandLinkButton_4_clicked()
{
    Dialog3 dialog3;
    dialog3.setModal(true);
    dialog3.exec();
}

void Dialog14::on_commandLinkButton_5_clicked()
{
    Dialog8 dialog8;
    dialog8.setModal(true);
    dialog8.exec();
}

void Dialog14::on_commandLinkButton_3_clicked()
{
    Dialog4 dialog4;
    dialog4.setModal(true);
    dialog4.exec();
}

void Dialog14::on_pushButton_clicked()
{
    in = new MainWindow();
    in->show();
    this->close();
}

void Dialog14::on_commandLinkButton_6_clicked()
{
    this->close();
    Dialog17 dialog17;
    dialog17.setModal(true);
    dialog17.exec();
}
