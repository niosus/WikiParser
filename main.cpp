#include "mainwindow.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::getInstance();
    w->show();

    Controller controller;
    controller.start();

    return a.exec();
}
