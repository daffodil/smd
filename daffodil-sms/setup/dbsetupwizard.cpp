#include "dbsetupwizard.h"
#include "dbwizzmysqlpage.h"

#include <QtGui/QIcon>

DbSetupWizard::DbSetupWizard(QWidget *parent) :
    QWizard(parent)
{

    setWindowIcon(QIcon(":/icons/settings"));
    setWindowTitle("Database Storge Settings");

    addPage( new DbWizzSelectPage() );

    addPage( new DbWizzMySqlPage() );


}
