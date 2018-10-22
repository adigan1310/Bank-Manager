#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog14.h"
#include "dialog15.h"
#include "dialog16.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("E:/bp.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString pass,text;
    text=ui->lineEdit->text();
    pass=ui->lineEdit_2->text();
    connnOpen();
    QSqlQuery qry;
    if(text=="mangr")
    {
    if(qry.exec("select * from login where username='"+text+"' and password='"+pass+"'"))
    {
       int count=0;
       while(qry.next())
       {
           count++;
       }
       if(count==1)
       {   this->close();
           connnClose();
           Dialog dialog;
           dialog.setModal(true);
           dialog.exec();

       }
       else
           ui->label_4->setText("incorrect username and password");
    }
    }
    else if(text=="savban")
    {
        if(qry.exec("select * from login where username='"+text+"' and password='"+pass+"'"))
        {
           int count=0;
           while(qry.next())
           {
               count++;
           }
           if(count==1)
           {   this->close();
               Dialog14 dialog14;
               dialog14.setModal(true);
               dialog14.exec();
               connnClose();
           }
           else
               ui->label_4->setText("incorrect username and password");
        }
    }

   else if(text=="ejloan")
    {
        if(qry.exec("select * from login where username='"+text+"' and password='"+pass+"'"))
        {
           int count=0;
           while(qry.next())
           {
               count++;
           }
           if(count==1)
           {   this->close();
               connnClose();
               Dialog15 dialog15;
               dialog15.setModal(true);
               dialog15.exec();

           }
           else
               ui->label_4->setText("incorrect username and password");
        }
    }

   else if(text=="rdfd")
    {
        if(qry.exec("select * from login where username='"+text+"' and password='"+pass+"'"))
        {
           int count=0;
           while(qry.next())
           {
               count++;
           }
           if(count==1)
           {   this->close();
               connnClose();
               Dialog16 dialog16;
               dialog16.setModal(true);
               dialog16.exec();

           }
           else
               ui->label_4->setText("incorrect username and password");
        }
    }
    else
        ui->label_4->setText("incorrect username and password");
}
