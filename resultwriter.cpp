#include "resultwriter.h"
#include <QString>

void ResultWriter::writeToFile(const WordsCountHash &words)
{
    QFile file("words_with_count.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    qint64 counter = 0;
    qint64 allWordsCount = words.size();
    for (auto key: words.keys())
    {
        QString MyOutput = QString("%1\t%2\t\t%3\t%4").arg("COUNT", QString::number(words.value(key)), "WORD", key);
        out<<MyOutput<<endl;
        qreal percent = ((qreal)counter)/allWordsCount*100;
        counter++;
        emit progressUpdate(percent);
    }
    emit fileWritten();
    file.close();
}
