#include "providerdialog.h"

#include <QtGui/QIcon>

ProviderDialog::ProviderDialog(QDialog *parent) :
    QDialog(parent)
{

    setWindowIcon(QIcon(":/icons/provider"));
    setWindowTitle("Provider");

}
