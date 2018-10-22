#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;

    void connnClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connnOpen()
    {
          mydb=QSqlDatabase::addDatabase("QSQLITE");
          mydb.setDatabaseName("C:/sqlite/login.db");
          if(!mydb.open())
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
