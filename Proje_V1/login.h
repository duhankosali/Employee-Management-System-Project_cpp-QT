#ifndef LOGIN_H
#define LOGIN_H

#include "calisanbilgileri.h"

#include <QMainWindow>
#include <QMessageBox>

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose() // database bağlantı kesme fonksiyonu
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen() // database bağlanma fonksiyonu
    {
                mydb = QSqlDatabase::addDatabase("QSQLITE");
                mydb.setDatabaseName("D:/SQStudio/denemeDB");
                if(!mydb.open())
                {
                    qDebug()<< ("Veri tabanına bağlanılamadı.");
                    return false;
                }
                else
                {
                   qDebug()<<("Veri tabanına bağlanılıyor...");
                    return true;
                }
    }

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_girisButton_clicked();


private:
    Ui::Login *ui;




};
#endif // LOGIN_H
