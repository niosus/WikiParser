#include "filereader.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QMapIterator>
#include <QString>
#include <QVector>

void FileReader::readFile()
{
    QFile * wordsFile = new QFile("/home/igor/words_with_count.dat");
    if (!wordsFile->open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(new QWidget,"No Words File",
        "words file does not exist",
        QMessageBox::Ok);
        return;
    }
    QMap<qint64, QVector<QString> > wordsCountMap;
    QTextStream wordsStream(wordsFile);
    while(!wordsStream.atEnd()) {
        QString line = wordsStream.readLine();
        QStringList fields = line.split(" ",QString::SkipEmptyParts);
        qint64 count = fields[1].toLongLong();
        QString name = fields[3];
//        qDebug()<<name<<count;
        wordsCountMap[count].push_back(name);
    }
    wordsFile->close();
    delete wordsFile;

    qDebug()<< " !!!!!!! 100 MOST USED WORDS !!!!!!!!!!"<<endl<<endl;
    QMapIterator<qint64, QVector<QString> > iter(wordsCountMap);
    iter.toBack();
    int counter = 0;
    while (counter < 100)
    {
        qDebug()<<iter.previous().key()<<iter.previous().value()[0];
        counter++;
    }
}
