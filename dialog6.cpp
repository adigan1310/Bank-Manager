#include "dialog6.h"
#include "ui_dialog6.h"
#include<QMessageBox>
Dialog6::Dialog6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog6)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    resize(640,480);
}

Dialog6::~Dialog6()
{
    delete ui;
}

void Dialog6::on_pushButton_clicked()
{
    Dialog1 conn;
    QString amt,accno;
    amt=ui->lineEdit->text();
    accno=ui->lineEdit_2->text();
    int in=amt.toInt();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update member set acbal=acbal+'"+amt+"' where accno='"+accno+"'");
    if(in>=250&&in<50000)
    {
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Update"),tr("Updated..!"));
        this->close();
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Update"),tr("ERROR..!"));
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Enter valid amount..."));
    }

}

void Dialog6::on_pushButton_2_clicked()
{
   Dialog1 conn;
   QString accno;
   accno=ui->lineEdit_2->text();
   conn.connOpen();
   QSqlQuery qry;
   qry.prepare("select * from member where accno='"+accno+"'");
   if(qry.exec())
   {
       int count=0;
       while(qry.next())
       {
           count++;
       }
       if(count==1)
       {   QSqlQueryModel * modal = new QSqlQueryModel();
           QSqlQuery* qry = new QSqlQuery(conn.mydb1);
           qry->prepare("select fname,age,acbal from member where accno='"+accno+"'");
           qry->exec();
           modal->setQuery(*qry);
           ui->tableView->setModel(modal);
           ui->frame->setVisible(true);
           conn.connClose();
       }
       else
       {
           QMessageBox::critical(this,tr("Error"),tr("Not found"));
       }
   }
}
