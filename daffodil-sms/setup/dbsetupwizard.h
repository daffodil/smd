#ifndef DBSETUPWIZARD_H
#define DBSETUPWIZARD_H

#include <QtGui/QWidget>
#include <QtGui/QWizard>

#include "setup/dbwizzselectpage.h"
#include "setup/dbwizzmysqlpage.h"
#include "setup/dbwizzsqlitepage.h"

class DbSetupWizard : public QWizard
{
Q_OBJECT
public:
    explicit DbSetupWizard(QWidget *parent = 0);

    DbWizzSelectPage *wizzSelect;
    DbWizzSqlitePage *wizzSqlite;
    DbWizzMySqlPage *wizzMySql;

signals:

public slots:

};

#endif // DBSETUPWIZARD_H
