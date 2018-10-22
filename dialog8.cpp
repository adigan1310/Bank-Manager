#include "dialog8.h"
#include "ui_dialog8.h"
#include<QMessageBox>
Dialog8::Dialog8(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog8)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    ui->frame_2->setVisible(false);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    resize(640,480);
}

Dialog8::~Dialog8()
{
    delete ui;
}

void Dialog8::on_pushButton_13_clicked()
{
    Dialog1 conn;
    QString accno;
    accno=ui->lineEdit->text();
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
        {
            ui->frame->setVisible(true);
                ui->tableView->setVisible(true);
                QSqlQueryModel * modal = new QSqlQueryModel();
                QSqlQuery* qry = new QSqlQuery(conn.mydb1);
                qry->prepare("select * from member where accno='"+accno+"'");
                qry->exec();
                modal->setQuery(*qry);
                ui->tableView->setModel(modal);
                conn.connClose();
         }
        else
        {
            QMessageBox::critical(this,tr("Update"),tr("Account number not found.."));
            ui->lineEdit->setText("");
        }
    }
}

void Dialog8::on_pushButton_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("fname");
}

void Dialog8::on_pushButton_2_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("lname");
}

void Dialog8::on_pushButton_3_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("age");
}

void Dialog8::on_pushButton_4_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("sex");
}

void Dialog8::on_pushButton_5_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("dob");
}

void Dialog8::on_pushButton_6_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("address");
}

void Dialog8::on_pushButton_7_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("city");
}

void Dialog8::on_pushButton_8_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("pincode");
}

void Dialog8::on_pushButton_9_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("nationality");
}

void Dialog8::on_pushButton_10_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("acctype");
}

void Dialog8::on_pushButton_11_clicked()
{
}

void Dialog8::on_pushButton_12_clicked()
{
    ui->frame_2->setVisible(true);
    ui->label_4->setText("state");
}

void Dialog8::on_pushButton_14_clicked()
{
    this->close();
}

void Dialog8::on_commandLinkButton_clicked()
{
    QString accno,txt,disp;
    accno=ui->lineEdit->text();
    txt=ui->lineEdit_2->text();
    disp=ui->label_4->text();
    Dialog1 conn;
    conn.connOpen();
    QSqlQuery qry;
    if(disp=="fname")
    {
        qry.prepare("update member set fname='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="lname")
    {
        qry.prepare("update member set lname='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="age")
    {
        qry.prepare("update member set age='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="sex")
    {
        qry.prepare("update member set sex='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="dob")
    {
        qry.prepare("update member set dob='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="address")
    {
        qry.prepare("update member set address='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="city")
    {
        qry.prepare("update member set city='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="state")
    {
        qry.prepare("update member set state='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="pincode")
    {
        qry.prepare("update member set pincode='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="nationality")
    {
        qry.prepare("update member set nationality='"+txt+"' where accno='"+accno+"'");
    }
    if(disp=="acctype")
    {
        qry.prepare("update member set acty='"+txt+"' where accno='"+accno+"'");
    }
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Update"),tr("Updated..."));
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->label_4->setText("");
        conn.connClose();
        this->close();
    }
    else
    {
        QMessageBox::critical(this,tr("Update"),tr("Error..."));
    }
}
