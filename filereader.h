#ifndef FILEREADER_H
#define FILEREADER_H
#include <QString>
#include <QObject>

class FileReader: public QObject
{
    Q_OBJECT
public:
    FileReader() {}

public slots:
     void readFile();
};

#endif // FILEREADER_H
