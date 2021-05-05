#ifndef CALISANBILGILERI_H
#define CALISANBILGILERI_H

#include <QDialog>
#include "login.h"

namespace Ui {
class calisanbilgileri;
}

class calisanbilgileri : public QDialog
{
    Q_OBJECT

public:



    QString randsayi;

    explicit calisanbilgileri(QWidget *parent = nullptr);
    ~calisanbilgileri();

private slots:
    void on_ekleButton_clicked(); // Tabloya yeni çalışan ekleme metodu

    void on_silButton_clicked(); // Tablodan çalışan silme metodu

    void on_EditButton_clicked(); // Çalışan bilgisi düzenleme metodu

    void on_pushButton_clicked(); // Çalışanlar tablosunu görüntüleme metodu

    void on_pushButton_2_clicked(); // Başvurular tablosunu görüntüleme metodu

    QString randomSayi(); // Rastgele sayı oluşturur sonrasında sayıyı string değişkene çevirir.





private:

    Ui::calisanbilgileri *ui;

};

#endif // CALISANBILGILERI_H
