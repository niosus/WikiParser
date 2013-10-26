#ifndef RESULT_WRITER_H
#define RESULT_WRITER_H
#include <QHash>
#include <QFile>
#include <QTextStream>
#include "datagenerator.h"

class ResultWriter: public QObject
{
    Q_OBJECT

public slots:
    void writeToFile(const WordsCountHash &words);

signals:
    void progressUpdate(const qreal &percent);
    void fileWritten();
};

#endif // RESULT_WRITER_H
