#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "dialog1.h"
#include "dialog9.h"
#include "dialog3.h"
#include "dialog4.h"
#include "dialog8.h"
#include "dialog11.h"
#include "dialog13.h"
#include "dialog7.h"
#include "dialog18.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
        QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_commandLinkButton_clicked()
{
       Dialog1 dialog1;
       dialog1.setModal(true);
       dialog1.exec();
}

void Dialog::on_pushButton_clicked()
{
    in = new MainWindow();
    in->show();
    this->close();
}



void Dialog::on_commandLinkButton_2_clicked()
{
    Dialog9 dialog9;
    dialog9.setModal(true);
    dialog9.exec();

}

void Dialog::on_commandLinkButton_4_clicked()
{
    Dialog3 dialog3;
    dialog3.setModal(true);
    dialog3.exec();
}

void Dialog::on_commandLinkButton_3_clicked()
{
    Dialog4 dialog4;
    dialog4.setModal(true);
    dialog4.exec();
}

void Dialog::on_commandLinkButton_5_clicked()
{
    Dialog8 dialog8;
    dialog8.setModal(true);
    dialog8.exec();
}

void Dialog::on_commandLinkButton_7_clicked()
{
    Dialog11 dialog11;
    dialog11.setModal(true);
    dialog11.exec();
}

void Dialog::on_commandLinkButton_8_clicked()
{
    Dialog13 dialog13;
    dialog13.setModal(true);
    dialog13.exec();
}

void Dialog::on_commandLinkButton_6_clicked()
{
    Dialog7 dialog7;
    dialog7.setModal(true);
    dialog7.exec();
}

void Dialog::on_commandLinkButton_9_clicked()
{
    Dialog18 dialog18;
    dialog18.setModal(true);
    dialog18.exec();
}
