#ifndef WORKER_H
#define WORKER_H

#include "datagenerator.h"
#include "worker_thread.h"
#include "mainwindow.h"

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller() {
        DataGenerator *worker = new DataGenerator;
        worker->moveToThread(&workerThread);
//        connect(workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &Controller::start, worker, &DataGenerator::generateData);
        connect(worker, &DataGenerator::resultReady, this, &Controller::handleResults);
        connect(worker, &DataGenerator::progressUpdate, MainWindow::getInstance(), &MainWindow::progressUpdated);
        workerThread.start();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString &);
    void progressUpdated(const qreal &percent);
signals:
    void start();
};

#endif // WORKER_H
