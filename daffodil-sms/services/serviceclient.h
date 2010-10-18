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

    void credits();

protected:
    QString _user;
    QString _password;



signals:

public slots:

};

#endif // SERVICECLIENT_H
