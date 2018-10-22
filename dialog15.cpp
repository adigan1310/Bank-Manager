#include "dialog15.h"
#include "ui_dialog15.h"
#include "dialog11.h"
#include "dialog3.h"
#include "dialog17.h"
#include "dialog18.h"
#include "dialog19.h"
#include "dialog20.h"

Dialog15::Dialog15(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog15)
{
    ui->setupUi(this);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog15::~Dialog15()
{
    delete ui;
}

void Dialog15::on_pushButton_clicked()
{
    in = new MainWindow();
    in->show();
    this->close();
}

void Dialog15::on_commandLinkButton_7_clicked()
{
    Dialog11 dialog11;
    dialog11.setModal(true);
    dialog11.exec();
}

void Dialog15::on_commandLinkButton_4_clicked()
{
    Dialog3 dialog3;
    dialog3.setModal(true);
    dialog3.exec();
}

void Dialog15::on_commandLinkButton_6_clicked()
{
    Dialog20 dialog20;
    dialog20.setModal(true);
    dialog20.exec();
    this->close();
}

void Dialog15::on_commandLinkButton_9_clicked()
{
    Dialog18 dialog18;
    dialog18.setModal(true);
    dialog18.exec();
}

void Dialog15::on_commandLinkButton_8_clicked()
{
    Dialog19 dialog19;
    dialog19.setModal(true);
    dialog19.exec();
}
