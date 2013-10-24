#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QObject>
#include <QPointF>
#include <QVector>
#include <QHash>
#include <QXmlStreamReader>
#include <QPolygonF>

class DataGenerator: public QObject
{
    Q_OBJECT

public:
    DataGenerator();
    void generateData();

private:
    QHash<QString, int> _words;
    void getTitle(QXmlStreamReader *xmlReader);
    void getDataFromWikiXml();
};

#endif // DATAGENERATOR_H
