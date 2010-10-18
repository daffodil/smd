#ifndef SERVICECLIENT_H
#define SERVICECLIENT_H

#include <QObject>

class ServiceClient : public QObject
{
Q_OBJECT
public:
    explicit ServiceClient(QObject *parent = 0);

    QString user();
    void setUser(QString user);

    QString password();
    void setPassword(QString password);

    //* I think this needs to be virtual
    void credits();

protected:
    QString _user;
    QString _password;



signals:

public slots:

};

#endif // SERVICECLIENT_H
