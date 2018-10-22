#include "dialog17.h"
#include "ui_dialog17.h"
#include "mainwindow.h"
#include<QMessageBox>

Dialog17::Dialog17(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog17)
{
    ui->setupUi(this);
    QString text="savban";
    ui->label_6->setText(text);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    resize(640,480);
}

Dialog17::~Dialog17()
{
    delete ui;
}

void Dialog17::on_pushButton_clicked()
{
    MainWindow con;
    con.connnOpen();
    QString pss,rpss,text="savban";
    pss=ui->lineEdit_2->text();
    rpss=ui->lineEdit_3->text();
    QSqlQuery qry;
    qry.prepare("select * from login where username='"+text+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            if(pss==rpss)
            {
                qry.prepare("update login set password='"+pss+"' where username='"+text+"'");
                if(qry.exec())
                {
                    QMessageBox::information(this,tr("Save"),tr("Saved.."));
                    in = new MainWindow();
                    in->show();
                    this->close();
                    con.connnClose();
                }
            }
            else
            {
                QMessageBox::critical(this,tr("Error"),tr("Password do not match"));
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),tr("Id not available."));
        }
    }
}
