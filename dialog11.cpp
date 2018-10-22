#include "dialog11.h"
#include "ui_dialog11.h"
#include<QMessageBox>

Dialog11::Dialog11(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog11)
{
        ui->setupUi(this);
        ui->frame->setVisible(false);
        ui->groupBox->setVisible(false);
        ui->label_6->setVisible(false);
        QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

}

Dialog11::~Dialog11()
{
    delete ui;
}

void Dialog11::on_commandLinkButton_clicked()
{
    QString wt,amt,tot;
    int total;
    wt= ui->lineEdit->text();
    amt=ui->lineEdit_2->text();
    total=wt.toInt()*amt.toInt();
    tot=QString::number(total);
    ui->lineEdit_3->setText(tot);
    ui->groupBox->setVisible(true);
}

void Dialog11::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog11::on_pushButton_clicked()
{
    ui->frame->setVisible(true);
}

void Dialog11::on_pushButton_3_clicked()
{
    QString name,accno,amt,loty;
    loty="JEWEL";
    name=ui->lineEdit_4->text();
    amt=ui->lineEdit_3->text();
    accno=ui->lineEdit_7->text();
    Dialog1 conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare(" select * from member where accno='"+accno+"' and fname='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
           ui->label_6->setText(qry.value(14).toString());
        }
    }
    int bal=ui->label_6->text().toInt();
    if(bal==0)
    {
    if(amt!=""&&accno!=""&&name!="")
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
            QMessageBox::critical((this),tr("Loan"),tr("Please enter valid details."));
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
        QMessageBox::critical(this,tr("Error"),tr("Please finish the old loan to take new loan"));
    }
}
