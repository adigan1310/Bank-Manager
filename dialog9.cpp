#include "dialog9.h"
#include "ui_dialog9.h"
#include<QMessageBox>
Dialog9::Dialog9(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog9)
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

Dialog9::~Dialog9()
{
    delete ui;
}

void Dialog9::on_checkBox_clicked()
{
        Dialog1 conn;
        conn.connOpen();
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(conn.mydb1);
        qry->prepare("select accno,fname,lname from member");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        qDebug()<<(modal->rowCount());
        conn.connClose();
}

void Dialog9::on_pushButton_clicked()
{
    Dialog1 conn;
    QString accno;
    accno=ui->lineEdit->text();
    conn.connOpen();
    QSqlQuery qry;
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(conn.mydb1);
    qry.prepare("select * from member where accno='"+accno+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            qry1->prepare("select accno,fname,lname,acbal from member where accno='"+accno+"'");
            qry1->exec();
            modal->setQuery(*qry1);
            ui->tableView->setModel(modal);
            qDebug()<<(modal->rowCount());
            ui->frame->setVisible(true);
            conn.connClose();
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),tr("Not found"));
        }
    }
}

void Dialog9::on_pushButton_2_clicked()
{
       Dialog1 conn;
       QString accno;
       accno=ui->lineEdit->text();
       conn.connOpen();
       QSqlQuery qry;
       qry.prepare("Delete from member where accno='"+accno+"'");
       if(qry.exec())
       {
           QMessageBox::critical(this,tr("Delete"),tr("Deleted!!!"));
           conn.connClose();
           ui->lineEdit->setText("");
           this->close();
       }
}

void Dialog9::on_pushButton_3_clicked()
{
    this->close();
}
