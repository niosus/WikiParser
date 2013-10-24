#include "mainwindow.h"
#include "datagenerator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    DataGenerator dataGenerator;
    dataGenerator.generateData();

    return a.exec();
}
