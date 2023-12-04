#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RU-ru");
    system("chcp 1251");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
