#include "dialog1.h"
#include "ui_dialog1.h"
#include<QMessageBox>

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    ui->tableView->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->lineEdit_6->setText("dd/mm/yyyy");
        QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        resize(640,480);

}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog1::on_checkBox_pressed()
{

}

void Dialog1::on_pushButton_clicked()
{   QString accno,fname,lname,age,sex,dob,address,city,pincode,state,nationality,acty,acbal,loty,loamt,rdamt,fdamt;
    connOpen();
    QSqlQuery qry;
    fname=ui->lineEdit_2->text();
    lname=ui->lineEdit_3->text();
    age=ui->lineEdit_4->text();
    sex=ui->lineEdit_5->text();
    dob=ui->lineEdit_6->text();
    pincode=ui->lineEdit_12->text();
    state=ui->lineEdit_10->text();
    address=ui->lineEdit_7->text();
    nationality=ui->lineEdit_13->text();
    acty=ui->lineEdit_11->text();
    city=ui->lineEdit_9->text();
    acbal=ui->lineEdit_8->text();
    loty=ui->lineEdit_19->text();
    loamt=ui->lineEdit_20->text();
    rdamt=ui->lineEdit_21->text();
    fdamt=ui->lineEdit_22->text();
    accno=ui->lineEdit_18->text();

    if(fname!=""&&lname!=""&&age!=""&&sex!=""&&dob!=""&&pincode!=""&&state!=""&&address!=""&&nationality!=""&&acty!=""&&city!=""&&acbal!=""&&loty!=""&&loamt!=""&&rdamt!=""&&fdamt!=""&&accno!="")
    {
        if(age.toInt()>0&&age.toInt()<100&&acbal.toInt()>=1000)
       {

    qry.prepare("select * from member where accno='"+accno+"' and fname='"+fname+"' and age='"+age+"' and dob ='"+dob+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            QMessageBox::critical(this,tr("Message"),tr("Account already in use..."));
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            ui->lineEdit_4->setText("");
            ui->lineEdit_5->setText("");
            ui->lineEdit_6->setText("dd/mm/yyyy");
            ui->lineEdit_7->setText("");
            ui->lineEdit_8->setText("");
            ui->lineEdit_9->setText("");
            ui->lineEdit_10->setText("");
            ui->lineEdit_11->setText("");
            ui->lineEdit_12->setText("");
            ui->lineEdit_13->setText("");
            ui->lineEdit_18->setText("");
            ui->lineEdit_19->setText("");
            ui->lineEdit_20->setText("");
            ui->lineEdit_21->setText("");
            ui->lineEdit_22->setText("");
        }
        else
        {
            qry.prepare("insert into member values('"+fname+"','"+lname+"','"+age+"','"+sex+"','"+dob+"','"+address+"','"+city+"','"+pincode+"','"+state+"','"+nationality+"','"+acty+"','"+acbal+"','"+accno+"','"+loty+"','"+loamt+"','"+rdamt+"','"+fdamt+"')");
            if(qry.exec())
             {

                         QMessageBox::information(this,tr("Save"),tr("saved..."));
                         connClose();
                         ui->tableView->setVisible(true);
                         ui->lineEdit_2->setText("");
                         ui->lineEdit_3->setText("");
                         ui->lineEdit_4->setText("");
                         ui->lineEdit_5->setText("");
                         ui->lineEdit_6->setText("dd/mm/yyyy");
                         ui->lineEdit_7->setText("");
                         ui->lineEdit_8->setText("");
                         ui->lineEdit_9->setText("");
                         ui->lineEdit_10->setText("");
                         ui->lineEdit_11->setText("");
                         ui->lineEdit_12->setText("");
                         ui->lineEdit_13->setText("");
                         ui->lineEdit_18->setText("");
                         ui->lineEdit_19->setText("");
                         ui->lineEdit_20->setText("");
                         ui->lineEdit_21->setText("");
                         ui->lineEdit_22->setText("");

             }
             else
             {
                         QMessageBox::critical(this,tr("NotSave"),tr("Not Saved..."));
             }
        }
     }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),tr("Please fill in proper details."));
        }
    }

    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Please fill in all the details."));
    }

}


void Dialog1::on_radioButton_clicked()
{   Dialog1 con;
    con.connOpen();
    ui->tableView->setVisible(true);
    ui->pushButton->setVisible(true);
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(con.mydb1);
    qry->prepare("select accno from member");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    qDebug()<<(modal->rowCount());
    con.connClose();
}
