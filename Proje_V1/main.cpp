#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login giris;
    giris.show();
    return a.exec();
}
