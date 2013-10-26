#ifndef WORKER_THREAD_H
#define WORKER_THREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
    void run() Q_DECL_OVERRIDE {
        QString result;
        /* expensive or blocking operation  */
        emit resultReady(result);
    }
signals:
    void resultReady(const QString &s);
};

#endif // WORKER_THREAD_H
