#include "dialog18.h"
#include "ui_dialog18.h"
#include<QMessageBox>
Dialog18::Dialog18(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog18)
{
    ui->setupUi(this);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    resize(640,480);
    ui->label_7->setVisible(false);
}

Dialog18::~Dialog18()
{
    delete ui;
}

void Dialog18::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog18::on_pushButton_clicked()
{
    QString name,accno,amt,loty;
    name=ui->lineEdit->text();
    amt=ui->lineEdit_3->text();
    accno=ui->lineEdit_2->text();
    loty="edu";
    Dialog1 conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from member where accno='"+accno+"' and fname='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
           ui->label_7->setText(qry.value(14).toString());
        }
    }
    int bal=ui->label_7->text().toInt();
    if(bal==0)
    {if(amt!="")
        {
    qry.prepare("select * from member where accno='"+accno+"' and fname='"+name+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            qry.prepare("update member set loty='"+loty+"',loamt='"+amt+"' where accno='"+accno+"'");
            if(qry.exec())
            {
                QMessageBox::information(this,tr("Loan"),tr("Saved..."));
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
            QMessageBox::critical(this,tr("Loan"),tr("Not a bank member cant take loan"));
        }
    }
        }
        else
        {
            QMessageBox::critical(this,tr("Loan"),tr("Please enter a valid amount"));
        }
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Please finish the old loan to take new one."));
        this->close();
    }
}
