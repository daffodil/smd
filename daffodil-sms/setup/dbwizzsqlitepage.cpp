#include "dbwizzsqlitepage.h"

#include <QtGui/QVBoxLayout>
#include <QtGui/QButtonGroup>
#include <QtGui/QRadioButton>

DbWizzSqlitePage::DbWizzSqlitePage(QWidget *parent) :
    QWizardPage(parent)
{

    QVBoxLayout *mainVBox = new QVBoxLayout();
    setLayout(mainVBox);

    setTitle("Select Database Driver");

    QButtonGroup *grpRadio = new QButtonGroup(this);
    connect(grpRadio, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(on_radio_button_clicked)
    );

    QRadioButton *radioSqlite = new QRadioButton();
    grpRadio->addButton(radioSqlite);
    mainVBox->addWidget(radioSqlite);
    radioSqlite->setText("Sqlite database - local to this machine only");
    radioSqlite->setChecked(true);

    QRadioButton *radioMySql = new QRadioButton();
    grpRadio->addButton(radioMySql);
    mainVBox->addWidget(radioMySql);
    radioMySql->setText("MySql database - network database");

    QRadioButton *radioMsSql = new QRadioButton();
    grpRadio->addButton(radioMsSql);
    mainVBox->addWidget(radioMsSql);
    radioMsSql->setText("Microsoft SQL database - network database");
    radioMsSql->setDisabled(true);

}
