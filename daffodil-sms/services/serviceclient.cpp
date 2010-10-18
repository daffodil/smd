#include "serviceclient.h"

ServiceClient::ServiceClient(QObject *parent) :
    QObject(parent)
{
}

QString ServiceClient::user(){
    return _user;
}
void ServiceClient::setUser(QString user){
    _user = user;
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
