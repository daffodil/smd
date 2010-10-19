#include "providerdialog.h"

#include <QtCore/QtDebug>
#include <QtCore/QUrl>

#include <QtGui/QLabel>
#include <QtGui/QIcon>
#include <QtGui/QVBoxLayout>
#include <QtGui/QButtonGroup>
#include <QtGui/QDesktopServices>

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>


ProviderDialog::ProviderDialog(MainObject *mOb, QDialog *parent) :
    QDialog(parent)
{
    mainObject = mOb;
    //provider = prov;

    //setFixedWidth(300);
    setWindowIcon(QIcon(":/icons/provider"));
    setWindowTitle("Provider");


    QVBoxLayout *mainOuterLayout = new QVBoxLayout();
    this->setLayout(mainOuterLayout);
    mainOuterLayout->setContentsMargins(0,0,0,0);
    mainOuterLayout->setSpacing(0);

    //** Header Label
    headerLabel = new QLabel();
    headerLabel->setText("-- provider --");
    headerLabel->setStyleSheet("font-size: 20pt; background-color: white; color: green;");
    mainOuterLayout->addWidget(headerLabel);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainOuterLayout->addLayout(mainLayout);
    mainLayout->setContentsMargins(20,20,20,20);
    mainLayout->setSpacing(10);


    QString styleGrp = QString("QGroupBox{  border:2px solid gray;border-radius:5px;  margin-top: 1ex;} QGroupBox::title{subcontrol-origin: margin;subcontrol-position:top center;padding:0 3px;}");

    //***************************************************
    //** Browse Button Group
    QGroupBox *grpBrowse = new QGroupBox();
    grpBrowse->setTitle("Open in web browser..");
    grpBrowse->setStyleSheet(styleGrp);
    mainLayout->addWidget(grpBrowse);
    QHBoxLayout *grpBrowseLayout = new QHBoxLayout();
    grpBrowse->setLayout(grpBrowseLayout);

    //** Browser Buttons
    QButtonGroup *buttonGroupBrowse = new QButtonGroup(this);
    connect(buttonGroupBrowse, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(on_browse_button(QAbstractButton*))
    );

    buttHomePage = new QPushButton();
    buttHomePage->setText("Home page");
    grpBrowseLayout->addWidget(buttHomePage);
    buttonGroupBrowse->addButton(buttHomePage);

    buttPrices = new QPushButton();
    buttPrices->setText("Prices");
    grpBrowseLayout->addWidget(buttPrices);
    buttonGroupBrowse->addButton(buttPrices);

    buttSignUp = new QPushButton();
    buttSignUp->setText("Sign Up");
    grpBrowseLayout->addWidget(buttSignUp);
    buttonGroupBrowse->addButton(buttSignUp);

    buttLogin = new QPushButton();
    buttLogin->setText("Login");
    grpBrowseLayout->addWidget(buttLogin);
    buttonGroupBrowse->addButton(buttLogin);




   // chkboxActive = new QCheckBox();
   // mainLayout->addWidget(chkboxActive);
    //chkboxActive->setText("Activate this account");
    //*************************************************************
    //** Credentials
    grpCredentials = new QGroupBox();
    grpCredentials->setTitle("Account Details");
    grpCredentials->setCheckable(true);
    grpCredentials->setStyleSheet(styleGrp);
    mainLayout->addWidget(grpCredentials);

    QVBoxLayout *credLayout = new QVBoxLayout();
    grpCredentials->setLayout(credLayout);

    QLabel *lblUsername = new QLabel("Username");
    credLayout->addWidget( lblUsername );
    txtUsername = new QLineEdit();
    credLayout->addWidget(txtUsername);


    QLabel *lblPassword = new QLabel("Password");
    credLayout->addWidget( lblPassword );
    txtPass = new QLineEdit();
    credLayout->addWidget(txtPass);



}
void ProviderDialog::loadProvider(QString provider)
{
    _provider = provider;
    db_load();
}

void ProviderDialog::db_load()
{
    QSqlQuery query;
    query.prepare("select active, provider, homepage, login, prices, signup from providers where provider=?;");
    query.addBindValue( _provider );
    qDebug() << "provider=" << _provider;
    return;
    if(!query.exec()){
        qDebug() << "OOps=" << query.lastError();
        return;
    }else{
        query.next();
        qDebug() << "=" << query.lastQuery();
        headerLabel->setText(query.value(1).toString());
        buttHomePage->setToolTip(query.value(2).toString());
        buttLogin->setToolTip(query.value(3).toString());
        buttSignUp->setToolTip(query.value(5).toString());
        buttPrices->setToolTip(query.value(4).toString());
    }

    return;
}




void ProviderDialog::on_browse_button(QAbstractButton *button)
{
     qDebug() << "OOps=" << button->toolTip();
    QDesktopServices::openUrl(QUrl(button->toolTip()));
}
