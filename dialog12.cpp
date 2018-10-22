#include "dialog12.h"
#include "ui_dialog12.h"
#include<QMessageBox>
#include <QFile>
#include <QTextStream>

Dialog12::Dialog12(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog12)
{
        ui->setupUi(this);
        ui->frame_2->setVisible(false);
        ui->frame_6->setVisible(false);
        ui->frame_5->setVisible(false);
        QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

}

Dialog12::~Dialog12()
{
    delete ui;
}

void Dialog12::writefile()
{
    QString rec,payt,amt,bname;
    rec=ui->lineEdit->text();
    payt=ui->lineEdit_2->text();
    amt=ui->lineEdit_3->text();
    bname=ui->lineEdit_4->text();
            QString filename = "data.txt";
            QFile file(filename);
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QTextStream out(&file);
            out << "name :"<<bname<<"receiver :"<<rec<<"payable at :"<<payt<<"amount :"<<amt<<endl;
            file.close();
}

void Dialog12::on_radioButton_clicked()
{
    ui->frame_2->setVisible(true);
    ui->frame_6->setVisible(true);
}

void Dialog12::on_pushButton_clicked()
{
    ui->frame_5->setVisible(true);
    ui->frame->setVisible(false);

    QString rec,payt,amt,bname,bbranch,cno;
    rec=ui->lineEdit->text();
    payt=ui->lineEdit_2->text();
    amt=ui->lineEdit_3->text();
    bname=ui->lineEdit_4->text();
    bbranch=ui->lineEdit_5->text();
    cno=ui->lineEdit_6->text();
    ui->lineEdit_19->setText(rec);
    ui->lineEdit_20->setText(payt);
    ui->lineEdit_21->setText(amt);
    ui->lineEdit_16->setText(bname);
    ui->lineEdit_17->setText(bbranch);
    ui->lineEdit_18->setText(cno);
}

void Dialog12::on_pushButton_3_clicked()
{
    writefile();
    QMessageBox::information(this,tr("DD"),tr("Printing..."));
    this->close();
}

void Dialog12::on_commandLinkButton_clicked()
{
    QString amt,charg;
    amt=ui->lineEdit_3->text();
    charg=ui->lineEdit_8->text();
    int tot;
    tot=amt.toInt()+charg.toInt();
    QString dis;
    dis=QString::number(tot);
    ui->lineEdit_15->setText(dis);
}

void Dialog12::on_pushButton_4_clicked()
{
    QMessageBox::information(this,tr("DD"),tr("Printing..."));
    this->close();
}

void Dialog12::on_radioButton_3_clicked()
{
    ui->lineEdit_8->setText("25");
}

void Dialog12::on_radioButton_4_clicked()
{
    ui->lineEdit_8->setText("40");
}

void Dialog12::on_radioButton_2_clicked()
{
    ui->frame_2->setVisible(false);
    ui->frame_6->setVisible(false);
}
