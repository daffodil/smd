#ifndef TEXTMARKETER_H
#define TEXTMARKETER_H

#include "serviceclient.h"

class TextMarketer : public ServiceClient
{
Q_OBJECT
public:
    explicit TextMarketer(QObject *parent = 0);

signals:

public slots:

};

#endif // TEXTMARKETER_H
