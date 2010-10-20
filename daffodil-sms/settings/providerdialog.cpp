#include "providerdialog.h"

#include <QtCore/QtDebug>
#include <QtCore/QUrl>

#include <QtGui/QLabel>
#include <QtGui/QIcon>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QGridLayout>
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


    //QString styleGrp = QString("QGroupBox{  border:2px solid gray;border-radius:5px;  margin-top: 1ex;} QGroupBox::title{subcontrol-origin: margin;subcontrol-position:top left;padding:0px 3px;}");
    QString styleGrp = QString("QGroupBox{  border:1px solid gray; margin-top: 2ex;} QGroupBox::title{subcontrol-origin: margin;subcontrol-position:top left;padding:0px 3px;}");

    //***************************************************
    //** Browse Button Group
    QGroupBox *grpBrowse = new QGroupBox();
    grpBrowse->setTitle("Open in web browser..");
    grpBrowse->setStyleSheet(styleGrp);
    mainLayout->addWidget(grpBrowse);
    QHBoxLayout *grpBrowseLayout = new QHBoxLayout();
    grpBrowseLayout->setContentsMargins(10,10,10,10);
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


    mainLayout->addSpacing(20);

    //*************************************************************
    //** Credentials
    grpCredentials = new QGroupBox();
    grpCredentials->setTitle("Account Details");
    grpCredentials->setCheckable(true);
    grpCredentials->setStyleSheet(styleGrp);
    mainLayout->addWidget(grpCredentials);
    connect(grpCredentials, SIGNAL(clicked(bool)), this, SLOT(on_credentials_checkbox(bool)));

    QGridLayout *credLayout = new QGridLayout();
    credLayout->setContentsMargins(10,20,10,10);
    grpCredentials->setLayout(credLayout);
    int row =0;

    QLabel *lblUsername = new QLabel("Username");
    credLayout->addWidget( lblUsername, row, 0 );

    txtUsername = new QLineEdit();
    credLayout->addWidget(txtUsername, ++row, 0, 1, 1);


    QLabel *lblPassword = new QLabel("Password");
    credLayout->addWidget( lblPassword, ++row, 0, 1, 1 );
    txtPass = new QLineEdit();
    credLayout->addWidget(txtPass, ++row, 0, 1, 1);
    //credLayout->addSpacing(10);

    QLabel *lblEmail = new QLabel("Email");
    credLayout->addWidget( lblEmail, ++row, 0 );
    txtEmail = new QLineEdit();
    credLayout->addWidget(txtEmail, ++row, 0, 1, 2);

    credLayout->setColumnStretch(0,1);
    credLayout->setColumnStretch(1,1);

    mainLayout->addSpacing(20);


    //**************************************************
    //** Buttons
    QHBoxLayout *buttonBox = new QHBoxLayout();
    mainLayout->addLayout(buttonBox);
    buttonBox->addStretch(10);

    QPushButton *cancelButton = new QPushButton();
    cancelButton->setText("Cancel");
    cancelButton->setIcon(QIcon(":/icons/black"));
    buttonBox->addWidget(cancelButton);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(on_cancel()));

    QPushButton *saveButton = new QPushButton();
    saveButton->setText("Save");
    saveButton->setIcon(QIcon(":/icons/ok"));
    buttonBox->addWidget(saveButton);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(on_save()));

    statusBar = new XStatusBar();
    mainOuterLayout->addWidget(statusBar);
    statusBar->showMessage("Loaded", 2000);


}
void ProviderDialog::loadProvider(QString provider)
{
    _provider = provider;
    db_load();
}

void ProviderDialog::db_load()
{
    QSqlQuery query;
    query.prepare("select active, provider, homepage, login, prices, signup, username, password from providers where provider=?;");
    query.addBindValue( _provider );
    qDebug() << "provider=" << _provider;
    //return;
    if(!query.exec()){
        qDebug() << "OOps=" << query.lastError();
        return;
    }else{
        query.next();
        qDebug() << "=" << query.lastQuery();
        headerLabel->setText(query.value(1).toString());
        grpCredentials->setChecked(query.value(0).toBool() ? Qt::Checked : Qt::Unchecked);
        buttHomePage->setToolTip(query.value(2).toString());
        buttLogin->setToolTip(query.value(3).toString());
        buttSignUp->setToolTip(query.value(5).toString());
        buttPrices->setToolTip(query.value(4).toString());
    }

    return;
}




void ProviderDialog::on_browse_button(QAbstractButton *button)
{
    QDesktopServices::openUrl(QUrl(button->toolTip()));
}

void ProviderDialog::on_credentials_checkbox(bool state)
{
    if(state){
        txtUsername->setFocus();
    }
}


void ProviderDialog::on_cancel()
{
    reject();
}


void ProviderDialog::on_save()
{
    txtUsername->setText(txtUsername->text().trimmed());
    if(txtUsername->text().length() == 0){
        statusBar->showError("Need an username", 4000);
        txtUsername->setFocus();
        return;
    }
    txtPass->setText(txtPass->text().trimmed());
    if(txtPass->text().length() == 0){
        statusBar->showError("Need a password", 4000);
        txtPass->setFocus();
        return;
    }
    QSqlQuery query;
    query.prepare("update providers set active=?, username=?, password=?, email=? where provider=?");
    query.addBindValue( grpCredentials->isChecked() ? 1 : NULL);
    query.addBindValue(txtUsername->text());
    query.addBindValue(txtPass->text());
    query.addBindValue(txtEmail->text());
    query.addBindValue(_provider);
    if(!query.exec()){
         qDebug() << query.lastError();
        return;
    }else{
        qDebug() << query.lastQuery();
    }
    accept();
}

