#include "dialog10.h"
#include "ui_dialog10.h"
#include<QMessageBox>
Dialog10::Dialog10(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog10)
{
    ui->setupUi(this);
    ui->frame_2->setVisible(false);
    ui->frame->setVisible(false);
    QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        resize(640,480);
}

Dialog10::~Dialog10()
{
    delete ui;
}

void Dialog10::on_pushButton_clicked()
{
    Dialog1 conn;
    QString accno,amt;
    int bal;
    accno=ui->lineEdit_2->text();
    conn.connOpen();
    QSqlQuery qry,qry1;
    qry.prepare(" select * from member where accno='"+accno+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
           ui->label_5->setText(qry.value(11).toString());
        }
    }
    amt=ui->lineEdit_3->text();
    bal=ui->label_5->text().toInt();
    if(amt.toInt()>0)
    {
    if(bal-amt.toInt()>0 && amt!="")
    {
     qry1.prepare("update member set acbal=acbal-'"+amt+"' where accno='"+accno+"' and acbal-'"+amt+"'>0");
     if(qry1.exec())
     {
        QMessageBox::information(this,tr("Update"),tr("Amount Withdrawn"));
        this->close();
        conn.connClose();
     }
     ui->frame_2->setVisible(true);
    }
    else
    {
        QMessageBox::critical(this,tr("Update"),tr("Error..."));
        ui->frame_2->setVisible(true);
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Enter a valid amount..."));
    }
}

void Dialog10::on_pushButton_2_clicked()
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
