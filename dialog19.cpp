#include "dialog19.h"
#include "ui_dialog19.h"
#include<QMessageBox>
Dialog19::Dialog19(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog19)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
}

Dialog19::~Dialog19()
{
    delete ui;
}

void Dialog19::on_pushButton_clicked()
{
    QString accno;
    Dialog1 conn;
    conn.connOpen();
    accno=ui->lineEdit->text();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.mydb1);
    qry->prepare("select fname,loty,loamt from member where accno='"+accno+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
   conn.connClose();
}

void Dialog19::on_pushButton_2_clicked()
{
    QString accno,amt;
    Dialog1 conn;
    conn.connOpen();
    accno=ui->lineEdit->text();
    amt=ui->lineEdit_2->text();
    QSqlQuery qry;
    qry.prepare(" select * from member where accno='"+accno+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
           ui->label->setText(qry.value(14).toString());
        }
    }
    int bal=ui->label->text().toInt();
    if(bal>0)
    {
    if(amt!=""&&accno!=""&&bal-amt.toInt()>=0)
    {
    qry.prepare("select * from member where accno='"+accno+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {  qry.prepare("update member set loamt='"+amt+"' where accno='"+accno+"'");
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Loan"),tr("Updated..."));
                conn.connClose();
                this->close();
            }
            else
            {
                QMessageBox::critical(this,tr("Loan"),tr("Error..."));
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Loan"),tr("Account not found."));
        }
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Enter valid information..."));
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("No loan amount to be paid."));
    }
}
