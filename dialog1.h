#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase mydb1;
    void connClose()
    {
        mydb1.close();
        mydb1.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
          mydb1=QSqlDatabase::addDatabase("QSQLITE");
          mydb1.setDatabaseName("C:/sqlite/member.db");
          if(!mydb1.open())
          {
              qDebug()<<"failed to open database";
              return false;
          }
          else
          {
              qDebug()<<"connected";
              return true;
          }
    }


public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_pressed();

    void on_pushButton_clicked();

    void on_radioButton_clicked();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
