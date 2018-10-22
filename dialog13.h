#ifndef DIALOG13_H
#define DIALOG13_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "dialog1.h"

namespace Ui {
class Dialog13;
}

class Dialog13 : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb3;
    void conClose()
    {
        mydb3.close();
        mydb3.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool conOpen()
    {
          mydb3=QSqlDatabase::addDatabase("QSQLITE");
          mydb3.setDatabaseName("C:/sqlite/rd.db");
          if(!mydb3.open())
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
    QSqlDatabase mydb4;
    void coClose()
    {
        mydb4.close();
        mydb4.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool coOpen()
    {
          mydb4=QSqlDatabase::addDatabase("QSQLITE");
          mydb4.setDatabaseName("C:/sqlite/fd.db");
          if(!mydb4.open())
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
    explicit Dialog13(QWidget *parent = 0);
    ~Dialog13();

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::Dialog13 *ui;
};

#endif // DIALOG13_H
