#include "dialog2.h"
#include "ui_dialog2.h"
#include <QMessageBox>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
        QPixmap bkgnd("D:/QT/untitled/untitled/Bank BG.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

Dialog2::~Dialog2()
{
    delete ui;
}


void Dialog2::on_pushButton_2_clicked()
{   QString accno;
    accno=ui->lineEdit->text();
    mydb2=QSqlDatabase::addDatabase("QSQLITE");
    mydb2.setDatabaseName("C:/sqlite/member.db");
    if(!mydb2.open())
    { qDebug()<<"failed to open database";
        return;
    }
    QSqlQuery qry;
    qry.prepare("Delete from member where acccno='"+accno+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("delete"),tr("Deleted!!!"));
            mydb2.close();
    }



}
