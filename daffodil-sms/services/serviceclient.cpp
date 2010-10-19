#include "serviceclient.h"

ServiceClient::ServiceClient(QObject *parent) :
    QObject(parent)
{
}

QString ServiceClient::username(){
    return _username;
}
void ServiceClient::setUsername(QString user){
    _username = user;
}

QString ServiceClient::password(){
    return _password;
}
void ServiceClient::setPassword(QString pass){
    _password = pass;
}


QString ServiceClient::credits(){
    return QString("base_credits()");
}
