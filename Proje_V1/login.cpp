#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/duhan/Desktop/Icons/login.png");
    ui->label_pic->setPixmap(pix);

    if(!connOpen())
        ui->label->setText("Veri tabanına bağlanılamadı.");
    else
        ui->label->setText("Veri tabanına bağlanıldı.");

}

Login::~Login()
{
    delete ui;
}



void Login::on_girisButton_clicked()
{
    QString stusername, stpassword;
    stusername = ui->username->text();
    stpassword = ui->password->text();

    if (!mydb.isOpen())
    {
       qDebug () << "Veri tabanına bağlanırken hata oluştu.";
       return;
    }
    QMessageBox msgbox;

    connOpen(); // veri tabanı bağlantımızı açıyoruz.

    QSqlQuery qry;
    qry.prepare("select * from employee where Username='"+stusername +"' and Password ='"+stpassword+"'");

    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count ++;
        }

        if(count==1) // Eğer kullanıcı adı ve parolası doğruysa yeni sayfaya geçer.
        {
            ui->label_4->setText("Kullanıcı adı ve parola doğru.");
            connClose(); // Parolamız doğru yani database kapatabiliriz.
            this->hide(); // önceki pencereyi gizler.
            calisanbilgileri calisanbilgi; // calisanbilgi adında bir nesne oluşturduk
            calisanbilgi.setModal(true);
            calisanbilgi.exec();
        }

        if(count>1)
            ui->label_4->setText("ss");
        if(count<1)
            ui->label_4->setText("Kullanıcı adı veya parola hatalı.");

    }

    else
        qDebug() << qry.lastError().text();
}
