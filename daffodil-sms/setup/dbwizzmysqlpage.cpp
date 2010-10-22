#include "dbwizzmysqlpage.h"

#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>

DbWizzMySqlPage::DbWizzMySqlPage(QWidget *parent) :
    QWizardPage(parent)
{

    QVBoxLayout *mainVBox = new QVBoxLayout();
    setLayout(mainVBox);

    setTitle("MySql Database details");

    //** Server
    mainVBox->addWidget(new QLabel("Server IP/Address"));
    QLineEdit *txtServer = new QLineEdit(this);
    mainVBox->addWidget(txtServer);
    mainVBox->addSpacing(10);

    //** Port
    mainVBox->addWidget(new QLabel("Port"));
    QLineEdit *txtPort = new QLineEdit(this);
    mainVBox->addWidget(txtPort);
    mainVBox->addSpacing(10);

    //** Username
    mainVBox->addWidget(new QLabel("Username"));
    QLineEdit *txtUsername = new QLineEdit(this);
    mainVBox->addWidget(txtUsername);
    mainVBox->addSpacing(10);

    //** Password
    mainVBox->addWidget(new QLabel("Password"));
    QLineEdit *txtPassword = new QLineEdit(this);
    mainVBox->addWidget(txtPassword);
    mainVBox->addSpacing(10);


    //** Password
    mainVBox->addWidget(new QLabel("Password"));
    QComboBox *comboDatabase = new QComboBox();
    comboDatabase->addItem("Foo");
    mainVBox->addWidget(comboDatabase);


}
