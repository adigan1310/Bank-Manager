#include "dialog5.h"
#include "ui_dialog5.h"
#include <QMessageBox>

Dialog5::Dialog5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog5)
{   ui->frame->setVisible(false);
    ui->setupUi(this);
    QPixmap bkgnd("E:/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog5::~Dialog5()
{
    delete ui;
}

void Dialog5::on_pushButton_clicked()
{  Dialog1 conn;
   QString accno;
   accno=ui->lineEdit->text();
   conn.connOpen();
   QSqlQuery qry;
   qry.prepare("Delete from member where accno='"+accno+"'");
   if(qry.exec())
   { QMessageBox::critical(this,tr("Delete"),tr("Deleted!!!"));
       conn.connClose();
       ui->lineEdit->setText("");
   }
   else
   { QMessageBox::critical(this,tr("Error"),tr("Error"));
   }
}

void Dialog5::on_checkBox_clicked()
{   Dialog1 conn;
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
