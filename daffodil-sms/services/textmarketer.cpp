#include "textmarketer.h"

TextMarketer::TextMarketer(QObject *parent) :
    ServiceClient(parent)
{
}

QString TextMarketer::credits(){
    return "mmm"; //QString("credits()");
}
