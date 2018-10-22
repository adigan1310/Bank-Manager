#include "dialog20.h"
#include "ui_dialog20.h"
#include<QMessageBox>
Dialog20::Dialog20(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog20)
{
    ui->setupUi(this);
    QString text="ejloan";
    ui->label_10->setText(text);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    resize(640,480);
}

Dialog20::~Dialog20()
{
    delete ui;
}

void Dialog20::on_pushButton_clicked()
{
    MainWindow con;
    con.connnOpen();
    QString pss,rpss,text="ejloan";
    pss=ui->lineEdit->text();
    rpss=ui->lineEdit_2->text();
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
