#include "calisanbilgileri.h"
#include "ui_calisanbilgileri.h"
#include "login.h"
#include "ui_login.h"

#include <QMessageBox>

calisanbilgileri::calisanbilgileri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calisanbilgileri)
{
    ui->setupUi(this);

    Login login; // login classımız için bir login nesnesi oluşturduk.

    if(!login.connOpen())
        ui->testlabel->setText("Veri tabanına bağlanılamadı.");
    else
        ui->testlabel->setText("Veri tabanına bağlanıldı.");  

}

class EmployeeInfo
{
public:
    QString id, name, surname, salary, worktime;

    QString getId(){return id;}
    void setId(QString idno) {id = idno;}

    QString getName(){return name;}
    void setName(QString isim) {name = isim;}

    QString getSurname(){return surname;}
    void setSurname(QString soyisim) {surname=soyisim;}

    QString getSalary(){return salary;}
    void setSalary(QString maas) {salary=maas;}

    QString getWorktime(){return worktime;}
    void setWorktime(QString isvakti) {worktime=isvakti;}

};


calisanbilgileri::~calisanbilgileri()
{
    delete ui;
}

QString calisanbilgileri::randomSayi() // Başvuru listesi için random sayı üreten string fonksiyonumuz
{
    int number;
    srand (time(NULL));
    number = rand() % 5 + 1; // 1 ile 5 arasında bir sayı
    QString rnd = QString::number(number);

    return rnd;
}

void calisanbilgileri::on_ekleButton_clicked() // tabloya yeni kişi ekleme metodu
{
    Login login; // Login classıyla bağlantılı bir login nesnesi oluşturuyoruz.
    EmployeeInfo calisanbilgi;
    /*
    QString id, name, surname, salary, worktime, username, password;
    id = ui->id_txt->text();
    name = ui->name_txt->text();
    surname = ui->surname_txt->text();
    salary = ui->salary_txt->text();
    worktime = ui->time_txt->text();
    */

    calisanbilgi.setId(ui->id_txt->text());
    calisanbilgi.setName(ui->name_txt->text());
    calisanbilgi.setSurname(ui->surname_txt->text());
    calisanbilgi.setSalary(ui->salary_txt->text());
    calisanbilgi.setWorktime(ui->time_txt->text());


    if (!login.connOpen())
    {
       qDebug () << "Veri tabanına bağlanırken hata oluştu.";
       return;
    }

    login.connOpen(); // veri tabanı bağlantımızı açıyoruz.

    if(ui->checkBox->isChecked())
    {


        QSqlQuery qry2;
        qry2.prepare("Delete from basvurular where numara='"+randsayi+"'");
        qry2.exec();
    }

    QSqlQuery qry;
    qry.prepare("insert into employee (id,name,surname,salary,worktime) values ('"+calisanbilgi.getId()+"','"+calisanbilgi.getName()+"','"+calisanbilgi.getSurname()+"','"+calisanbilgi.getSalary()+"','"+calisanbilgi.getWorktime()+"')");



    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Ekle"),tr("Eklendi"));

        login.connClose(); // database bağlantısını kestik.
    }

    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

    //check box kısmı





}



void calisanbilgileri::on_silButton_clicked()
{
    Login login; // Login classıyla bağlantılı bir login nesnesi oluşturuyoruz.
    EmployeeInfo calisanbilgi;
/*
    QString id, name, surname, salary, worktime, username, password;
    id = ui->id_txt->text();
    name = ui->name_txt->text();
    surname = ui->surname_txt->text();
    salary = ui->salary_txt->text();
     worktime = ui->time_txt->text();
*/
    calisanbilgi.setId(ui->id_txt->text());
    calisanbilgi.setName(ui->name_txt->text());
    calisanbilgi.setSurname(ui->surname_txt->text());
    calisanbilgi.setSalary(ui->salary_txt->text());
    calisanbilgi.setWorktime(ui->time_txt->text());




    if (!login.connOpen())
    {
       qDebug () << "Veri tabanına bağlanırken hata oluştu.";
       return;
    }

    login.connOpen(); // veri tabanı bağlantımızı açıyoruz.

    QSqlQuery qry;
    qry.prepare("Delete from employee where id='"+calisanbilgi.getId()+"'");


    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Sil"),tr("Silindi"));

        login.connClose(); // database bağlantısını kestik.
    }

    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}


void calisanbilgileri::on_EditButton_clicked()
{
    Login login; // Login classıyla bağlantılı bir login nesnesi oluşturuyoruz.
    EmployeeInfo calisanbilgi;

    /*QString id, name, surname, salary, worktime, username, password;
    id = ui->id_txt->text();
    name = ui->name_txt->text();
    surname = ui->surname_txt->text();
    salary = ui->salary_txt->text();
    worktime = ui->time_txt->text();*/

    calisanbilgi.setId(ui->id_txt->text());
    calisanbilgi.setName(ui->name_txt->text());
    calisanbilgi.setSurname(ui->surname_txt->text());
    calisanbilgi.setSalary(ui->salary_txt->text());
    calisanbilgi.setWorktime(ui->time_txt->text());

    if (!login.connOpen())
    {
       qDebug () << "Veri tabanına bağlanırken hata oluştu.";
       return;
    }

    login.connOpen(); // veri tabanı bağlantımızı açıyoruz.

    QSqlQuery qry;
    qry.prepare("Update employee set id='"+calisanbilgi.getId()+"',name='"+calisanbilgi.getName()+"',surname='"+calisanbilgi.getSurname()+"',salary='"+calisanbilgi.getSalary()+"',worktime='"+calisanbilgi.getWorktime()+"' where id='"+calisanbilgi.getId()+"'");


    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Güncelleme"));

        login.connClose(); // database bağlantısını kestik.
    }

    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void calisanbilgileri::on_pushButton_clicked()
{
    QString id = "3";
    Login login;
    QSqlQueryModel * modal=new QSqlQueryModel();

    login.connOpen(); // databaseye bağlanıyoruz.
    QSqlQuery* qry = new QSqlQuery(login.mydb);

    qry->prepare("select * from employee");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    login.connClose(); // database bağlantısını kesiyoruz.

    qDebug() << (modal->rowCount());
}

void calisanbilgileri::on_pushButton_2_clicked()
{
    Login login;
    calisanbilgileri calisan;
    /*int number;
    srand (time(NULL));
    number = rand() % 5 + 1; // 1 ile 5 arasında bir sayı
    QString rnd = QString::number(number);*/

    QSqlQueryModel * modal=new QSqlQueryModel();

    login.connOpen(); // databaseye bağlanıyoruz.
    QSqlQuery* qry = new QSqlQuery(login.mydb);
    randsayi=randomSayi();
    qry->prepare("select * from basvurular where numara='"+randsayi+"'"); // 5 tane başvurudan random 1 tanesini karşımıza çıkarıyor.

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    login.connClose(); // database bağlantısını kesiyoruz.

    qDebug() << (modal->rowCount());
}


