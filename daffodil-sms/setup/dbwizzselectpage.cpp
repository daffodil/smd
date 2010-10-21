#include "dbwizzselectpage.h"

#include <QtGui/QVBoxLayout>
#include <QtGui/QButtonGroup>
#include <QtGui/QRadioButton>

DbWizzSelectPage::DbWizzSelectPage(QWidget *parent) :
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
    radioSqlite->setText("Sqlite database - local to this machine only");

    QRadioButton *radioMySql = new QRadioButton();
    grpRadio->addButton(radioMySql);
    radioMySql->setText("MySql database - network database");

    QRadioButton *radioMsSql = new QRadioButton();
    grpRadio->addButton(radioMsSql);
    radioMsSql->setText("Microsoft Sql database - network database");

}
