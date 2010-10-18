#ifndef X24COM_H
#define X24COM_H

#include "serviceclient.h"

class X24Com : public ServiceClient
{
Q_OBJECT
public:
    explicit X24Com(QObject *parent = 0);

    QString credits();

signals:

public slots:

};

#endif // X24COM_H
