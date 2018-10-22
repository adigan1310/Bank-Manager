#include "dialog21.h"
#include "ui_dialog21.h"
#include<QMessageBox>
Dialog21::Dialog21(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog21)
{
    ui->setupUi(this);
    QString text="rdfd";
    ui->label_10->setText(text);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    resize(640,480);
}

Dialog21::~Dialog21()
{
    delete ui;
}

void Dialog21::on_pushButton_clicked()
{
    MainWindow con;
    con.connnOpen();
    QString pss,rpss,text="rdfd";
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
