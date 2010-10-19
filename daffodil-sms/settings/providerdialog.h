#ifndef PROVIDERDIALOG_H
#define PROVIDERDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QCheckBox>
#include <QtGui/QAbstractButton>
#include <QtGui/QPushButton>
#include <QtGui/QGroupBox>
#include <QtGui/QLineEdit>

#include <QtCore/QString>


#include "mainobject.h"

class ProviderDialog : public QDialog
{
Q_OBJECT
public:
    explicit ProviderDialog(MainObject *mOb, QDialog *parent = 0);

    MainObject *mainObject;
    QLabel *headerLabel;

    void loadProvider(QString provider);

    QCheckBox *chkboxActive;

    QPushButton *buttHomePage;
    QPushButton *buttSignUp;
    QPushButton *buttLogin;
    QPushButton *buttPrices;

    QGroupBox *grpCredentials;

    QLineEdit *txtUsername;
    QLineEdit *txtPass;
    QLineEdit *txtEmail;

private:
    QString _provider;

signals:

public slots:
    void db_load();
    void on_browse_button(QAbstractButton*);
};

#endif // PROVIDERDIALOG_H
