#include "controller.h"
#include <QDebug>

void Controller::progressUpdated(const qreal &percent)
{
    qDebug()<<percent << "%";
}
