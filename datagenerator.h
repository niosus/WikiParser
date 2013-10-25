#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QObject>
#include <QPointF>
#include <QVector>
#include <QMap>
#include <QXmlStreamReader>
#include <QPolygonF>

class DataGenerator: public QObject
{
    Q_OBJECT

public:
    DataGenerator();


public slots:
     void generateData();

private:
    QMap<QString, int> _words;
    void getTitle(QXmlStreamReader *xmlReader);
    void getDataFromWikiXml();
    void showData();

signals:
    void resultReady(const QString &result);
    void progressUpdate(const qreal &persent);

};

#endif // DATAGENERATOR_H
