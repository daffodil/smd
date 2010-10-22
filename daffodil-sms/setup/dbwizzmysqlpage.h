#ifndef DBWIZZMYSQLPAGE_H
#define DBWIZZMYSQLPAGE_H

#include <QWizardPage>

#include <QtGui/QLineEdit>
#include <QtGui/QComboBox>


class DbWizzMySqlPage : public QWizardPage
{
Q_OBJECT
public:
    explicit DbWizzMySqlPage(QWidget *parent = 0);

    QLineEdit *txtServer;
    QLineEdit *txtPort;
    QLineEdit *txtUsername;
    QLineEdit *txtPassword;
    QComboBox *comboDatabase;

signals:

public slots:

};

#endif // DBWIZZMYSQLPAGE_H
