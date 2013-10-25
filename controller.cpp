#include "controller.h"
#include <QDebug>

void Controller::handleResults(const QString &)
{

}

void Controller::progressUpdated(const qreal &percent)
{
    qDebug()<<percent << "%";
}
