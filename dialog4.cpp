#include "dialog4.h"
#include "ui_dialog4.h"
#include "dialog12.h"

Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
        QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        resize(640,480);
}

Dialog4::~Dialog4()
{
    delete ui;
}

void Dialog4::on_commandLinkButton_clicked()
{
    Dialog6 dialog1;
    dialog1.setModal(true);
    dialog1.exec();
}

void Dialog4::on_commandLinkButton_2_clicked()
{
    Dialog10 dialog10;
    dialog10.setModal(true);
    dialog10.exec();
}

void Dialog4::on_commandLinkButton_4_clicked()
{
        Dialog12 dialog12;
        dialog12.setModal(true);
        dialog12.exec();
}
