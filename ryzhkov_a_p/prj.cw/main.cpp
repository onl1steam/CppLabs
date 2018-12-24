#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Hometown weather check
    w.makeRequest("Тамбов,Россия");
    w.show();

    return a.exec();
}


