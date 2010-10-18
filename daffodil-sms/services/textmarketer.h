#ifndef TEXTMARKETER_H
#define TEXTMARKETER_H

#include "serviceclient.h"

class TextMarketer : public ServiceClient
{
Q_OBJECT
public:
    explicit TextMarketer(QObject *parent = 0);

    //QString credits(); // << overrides base class

    QString credits();

signals:

public slots:

};

#endif // TEXTMARKETER_H
