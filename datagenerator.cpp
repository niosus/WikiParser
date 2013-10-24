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
    QXmlStreamReader *xmlReader = new QXmlStreamReader(xmlFile);
    qDebug() << "everything great here";
    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError())
    {
        // Read next element
        QXmlStreamReader::TokenType token = xmlReader->readNextStartElement();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        //If token is StartElement - read it

        if (xmlReader->name() == "text")
        {
            QString text = xmlReader->readElementText();
            QStringList words = text.split(" ", QString::SkipEmptyParts);
            for (auto word:words)
            {
                _words[word]++;
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
