#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
        ui->setupUi(this);
        QPixmap bkgnd("E:/bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        resize(640,480);
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_pushButton_clicked()
{
    Dialog1 conn;
    QString accno;
    accno=ui->lineEdit->text();
    conn.connOpen();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.mydb1);
    qry->prepare("select * from member where accno='"+accno+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());


}




void Dialog3::on_pushButton_2_clicked()
{
    this->close();
}
