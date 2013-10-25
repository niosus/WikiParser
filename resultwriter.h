#ifndef RESULT_WRITER_H
#define RESULT_WRITER_H
#include <QHash>
#include <QFile>
#include <QTextStream>

class ResultWriter: public QObject
{
    Q_OBJECT

public slots:
    void writeToFile(const QHash<QString, int> &words);
};

#endif // RESULT_WRITER_H
