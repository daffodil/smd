#include "x24com.h"

X24Com::X24Com(QObject *parent) :
    ServiceClient(parent)
{
}

QString X24Com::credits(){
    return "X24Com::credits()";
}
