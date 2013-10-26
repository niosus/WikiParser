#ifndef WORKER_H
#define WORKER_H

#include "datagenerator.h"
#include "worker_thread.h"
#include "resultwriter.h"
#include "mainwindow.h"

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller() {
        DataGenerator *worker = new DataGenerator;
        ResultWriter *resultWriter = new ResultWriter;
        worker->moveToThread(&workerThread);
        connect(this, &Controller::start, worker, &DataGenerator::generateData);
        connect(worker, &DataGenerator::progressUpdate, MainWindow::getInstance(), &MainWindow::progressUpdated);
        connect(resultWriter, &ResultWriter::progressUpdate, MainWindow::getInstance(), &MainWindow::progressUpdated);
        connect(resultWriter, &ResultWriter::fileWritten, MainWindow::getInstance(), &MainWindow::close);
        connect(worker, &DataGenerator::error, MainWindow::getInstance(), &MainWindow::showError);
        connect(worker, &DataGenerator::resultReady, resultWriter, &ResultWriter::writeToFile);
        workerThread.start();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void progressUpdated(const qreal &percent);
signals:
    void start();
};

#endif // WORKER_H
