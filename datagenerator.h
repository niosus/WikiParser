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


public slots:
     void generateData();

private:
    QHash<QString, qint64> _words;
    void getTitle(QXmlStreamReader *xmlReader);
    void getDataFromWikiXml();
    void showData();

signals:
    void resultReady(const QHash<QString, qint64> &words);
    void progressUpdate(const qreal &persent);
    void error(const QString &errorMessage);

};

#endif // DATAGENERATOR_H
