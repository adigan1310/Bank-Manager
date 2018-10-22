#include "dialog13.h"
#include "ui_dialog13.h"
#include<QMessageBox>

Dialog13::Dialog13(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog13)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    ui->frame_2->setVisible(false);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog13::~Dialog13()
{
    delete ui;
}

void Dialog13::on_checkBox_clicked()
{
    ui->frame->setVisible(true);
}

void Dialog13::on_checkBox_2_clicked()
{
    ui->frame_2->setVisible(true);
}

void Dialog13::on_pushButton_clicked()
{
    Dialog1 conn;
    conn.connOpen();
    QString name,age,td,amt,accno,acty;
    QSqlQuery qry;
    name=ui->lineEdit->text();age=ui->lineEdit_2->text();td=ui->lineEdit_3->text();
    amt=ui->lineEdit_4->text();accno=ui->lineEdit_5->text();
    acty=ui->lineEdit_13->text();
    if(amt!=""&&amt.toInt()>0)
    {
    qry.prepare("select * from member where acty='"+acty+"' and accno='"+accno+"' and fname='"+name+"'");
    if(qry.exec())
    {   int count=0;
        while(qry.next())
        {
            count++;
        }
          if(count==1)
           {
            qry.prepare("update member set rdamt='"+amt+"'");
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Rd"),tr("Saved..."));
                ui->lineEdit->setText("");ui->lineEdit_2->setText("");ui->lineEdit_3->setText("");
                ui->lineEdit_4->setText("");ui->lineEdit_5->setText("");ui->lineEdit_12->setText("");
                ui->lineEdit_13->setText("");
                conn.connClose();
            }
            else
            {
                QMessageBox::critical(this,tr("Rd"),tr("Error..."));
            }
        }
        else
        {
           QMessageBox::critical(this,tr("Rd"),tr("Not a bank member,cannot open a rd account.."));
        }
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Please fill in proper details.."));
    }
}

void Dialog13::on_pushButton_2_clicked()
{
    Dialog1 conn;
    conn.connOpen();
    QString name,age,yd,amt,accno,roi,acty;
    QSqlQuery qry;
    name=ui->lineEdit_6->text();age=ui->lineEdit_7->text();yd=ui->lineEdit_8->text();
    amt=ui->lineEdit_9->text();accno=ui->lineEdit_10->text();roi=ui->lineEdit_11->text();
    acty=ui->lineEdit_15->text();
    if(amt!=""&&amt.toInt()>0)
    {
    qry.prepare("select * from member where acty='"+acty+"' and accno='"+accno+"' and fname='"+name+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            qry.prepare("update member set fdamt='"+amt+"'");
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Fd"),tr("Saved..."));
                ui->lineEdit_6->setText("");ui->lineEdit_7->setText("");ui->lineEdit_8->setText("");
                ui->lineEdit_9->setText("");ui->lineEdit_10->setText("");ui->lineEdit_11->setText("");
                ui->lineEdit_14->setText("");ui->lineEdit_15->setText("");
                conn.connClose();
            }
            else
            {
                QMessageBox::critical(this,tr("Fd"),tr("Error..."));
            }
        }
        else
        {
            QMessageBox::critical((this),tr("Rd"),tr("Not a bank member,cannot open a fd account.."));
        }
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Please fill in proper details.."));
    }
}

void Dialog13::on_commandLinkButton_clicked()
{
    QString amt,roi,n;
    amt=ui->lineEdit_9->text();
    roi=ui->lineEdit_11->text();
    n=ui->lineEdit_8->text();
    float tot,r;
    r=roi.toFloat()/100;
    tot=(r*amt.toFloat())*n.toFloat();
    int total,tt;
    tt=static_cast<int>(tot);
    total=amt.toInt()+tt;
    QString t;
    t=QString::number(total);
    ui->lineEdit_14->setText(t);

}
