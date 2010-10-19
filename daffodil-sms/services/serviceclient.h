#ifndef SERVICECLIENT_H
#define SERVICECLIENT_H

#include <QtCore/QObject>
#include <QtCore/QString>

class ServiceClient : public QObject
{
Q_OBJECT
public:
    explicit ServiceClient(QObject *parent = 0);

    QString username();
    void setUsername(QString user);

    QString password();
    void setPassword(QString password);

    virtual QString credits();

protected:
    QString _username;
    QString _password;



signals:

public slots:

};

#endif // SERVICECLIENT_H
