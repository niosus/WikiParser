#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMovie>
#include <QMessageBox>

MainWindow* MainWindow::instance = nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    QMovie *movie = new QMovie(":res/spinner_blue.gif");
    ui->label_movie->setMovie(movie);
    ui->label_movie->setAutoFillBackground(true);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::progressUpdated(const qreal &percent)
{
    qDebug()<<percent;
    ui->progressBar->setValue(floor(percent));
}

void MainWindow::showError(const QString &errorMessage)
{
    QMessageBox::critical(new QWidget,
    "Error",errorMessage,
    QMessageBox::Ok);
}

void MainWindow::close()
{
    this->close();
}
