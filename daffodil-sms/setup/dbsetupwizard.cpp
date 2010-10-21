#include "dbsetupwizard.h"

#include "dbwizzselectpage.h"

DbSetupWizard::DbSetupWizard(QWidget *parent) :
    QWizard(parent)
{

    addPage(new DbWizzSelectPage());
}
