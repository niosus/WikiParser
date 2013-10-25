#include "resultwriter.h"
#include <QString>

void ResultWriter::writeToFile(const QHash<QString, int> &words)
{
    QFile file("words_with_count.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    for (auto key: words.keys())
    {
        QString MyOutput = QString("%1\t%2\t%3\t%4").arg("WORD", key, "COUNT", QString(words.value(key)));
        out<<MyOutput<<endl;
    }

    file.close();
}
