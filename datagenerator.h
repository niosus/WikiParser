#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QObject>
#include <QPointF>
#include <QVector>
#include <QHash>
#include <QXmlStreamReader>
#include <QPolygonF>

typedef QHash<QString, qint64> WordsCountHash;

class DataGenerator: public QObject
{
    Q_OBJECT

public:
    DataGenerator();

public slots:
     void generateData();

private:
    WordsCountHash _words;
    void getTitle(QXmlStreamReader *xmlReader);
    void getDataFromWikiXml();
    void showData();

signals:
    void resultReady(const WordsCountHash &words);
    void progressUpdate(const qreal &persent);
    void error(const QString &errorMessage);

};

Q_DECLARE_METATYPE(WordsCountHash);

#endif // DATAGENERATOR_H
