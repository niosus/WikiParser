#include "datagenerator.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include <cmath>


DataGenerator::DataGenerator(){}

void DataGenerator::generateData()
{
    getDataFromWikiXml();
    showData();
    emit resultReady("done");
}

void DataGenerator::showData()
{
    QMap<QString, int>::iterator iter = _words.end()-1;
    int counter = 0;
    const int maxCount = 100;
    while (true)
    {
        if (counter>maxCount)
        {
            break;
        }
        qDebug()<<iter.key() << iter.value();
    }
}

void DataGenerator::getTitle(QXmlStreamReader *xmlReader)
{
    QXmlStreamReader::TokenType token = xmlReader->readNext();
    if(token == QXmlStreamReader::StartElement)
    {
        if (xmlReader->name() == "title")
        {
            qDebug() << xmlReader->readElementText();
        }
        else
        {
            qDebug() <<"Something wrong,"<<xmlReader->name();
        }
    }
}

void DataGenerator::getDataFromWikiXml()
{
    QFile * xmlFile = new QFile("/home/igor/Documents/WikiDump/enwiki-20130904-pages-articles.xml");
    if (!xmlFile->open(QIODevice::ReadOnly)) {
            QMessageBox::critical(new QWidget,"Load Wiki Dump File Problem",
            "Couldn't load wiki xml file",
            QMessageBox::Ok);
            return;
    }
    qint64 fileSize = xmlFile->size();
    QXmlStreamReader *xmlReader = new QXmlStreamReader(xmlFile);
    qDebug() << "Started parsing document";
    qreal oldPercent = 0;
    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError())
    {
        // Read next element
        QXmlStreamReader::TokenType token = xmlReader->readNext();
        qint64 offset = xmlReader->characterOffset();
        qreal newPercent = ((qreal)offset/fileSize) * 100;
        if (newPercent>oldPercent+0.01)
        {
            oldPercent = newPercent;
            emit progressUpdate(newPercent);
        }

        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        //If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement)
        {
            if (xmlReader->name() == "text")
            {
                QString text = xmlReader->readElementText();
                QRegExp regExp("(\\W|\\d|\\_)");
                QStringList words = text.split(regExp, QString::SkipEmptyParts);
                for (QString word:words)
                {
                    if (word.length()>1)
                    {
                        word = word.toLower();
                        _words[word]++;
                    }
                }
            }
        }
    }

    if(xmlReader->hasError())
    {
        QMessageBox::critical(new QWidget,
        "xmlFile.xml Parse Error",xmlReader->errorString(),
        QMessageBox::Ok);
        return;
    }

    //close reader and flush file
    xmlReader->clear();
    xmlFile->close();
}
