#ifndef SERVICECLIENT_H
#define SERVICECLIENT_H

#include <QtCore/QObject>
#include <QtCore/QString>

class ServiceClient : public QObject
{
Q_OBJECT
public:
    explicit ServiceClient(QObject *parent = 0);

    QString user();
    void setUser(QString user);

    QString password();
    void setPassword(QString password);

    virtual QString credits();

protected:
    QString _user;
    QString _password;



signals:

public slots:

};

#endif // SERVICECLIENT_H
