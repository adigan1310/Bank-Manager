#include "dialog7.h"
#include "ui_dialog7.h"
#include<QMessageBox>

Dialog7::Dialog7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog7)
{
    ui->setupUi(this);

    QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        resize(640,480);
}

Dialog7::~Dialog7()
{
    delete ui;
}

void Dialog7::on_pushButton_clicked()
{
    QString logid,logpass;
    MainWindow con;
    QSqlQuery qry;
    logid=ui->lineEdit->text();
    logpass=ui->lineEdit_2->text();
    if(logid!="savban"&&logid!="rdfd"&&logid!="ejloan"&&logpass!="")
    {
    qry.prepare("insert into login values('"+logid+"','"+logpass+"')");
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Save"),tr("Saved..."));
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        con.connnClose();
    }
    }
    else
    {
        QMessageBox::critical(this,tr("Access"),tr("Please enter valid details."));
    }
}

void Dialog7::on_toolButton_clicked()
{
    this->close();
}

void Dialog7::on_checkBox_stateChanged(int arg1)
{
    if(arg1)
    {
        MainWindow con;
        ui->tableView->setVisible(true);
        con.connnOpen();
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery* qry = new QSqlQuery(con.mydb);
        qry->prepare("select username from login");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        qDebug()<<(modal->rowCount());

    }

    if(!arg1)
    {
        ui->tableView->setVisible(false);
    }

}
