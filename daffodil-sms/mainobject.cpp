
#include "mainobject.h"
#include "mainwindows/mainwindow.h"
//#include "settings/settingswidget.h"

#include <QtCore/QtDebug>

#include <QCoreApplication>
#include <QtGui/QDesktopServices>

#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QCursor>


#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>



MainObject::MainObject(QObject *parent) :
    QObject(parent)
{

    //**********************************************************************
    //** Settings connection
    settings = new QSettings();


    //********************************************************************
    //** SQL database problem
    // I dont want to connect et until required
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("localhost");
    //db.setUserName("root");
    //db.setPassword("mash");
    //db.setDatabaseName("ffs-desktop");
    qDebug() << QDesktopServices::storageLocation(QDesktopServices::DataLocation);
    db.setDatabaseName(QDesktopServices::storageLocation(QDesktopServices::DataLocation).append("daffodil-sms.sqlite"));
    if( !db.open() ){
        qDebug() << db.lastError();
        return;
    }
    if(!db_sanity_check()){
        qDebug() << "DB error";
        return;
    }

    //***********************************
    //** Tray Icon
    trayIcon = new QSystemTrayIcon(QIcon(":/icons/favicon"), this);
    trayIcon->setToolTip("FlightGear Launcher");
    trayIcon->setVisible(true);
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(on_tray_icon(QSystemTrayIcon::ActivationReason)));


    //***********************************
    //** Menu and actions
    popupMenu = new QMenu();
    trayIcon->setContextMenu(popupMenu);

    actionCallsign = new QWidgetAction(this);
    lblCallsign = new QLabel();
    lblCallsign->setText("CALLSIGN");
    lblCallsign->setStyleSheet("font-family: monospace; background-color: black; color: white; padding: 5px; font-weight: bold;");




    //*** Settings
    QAction *actionSettings= new QAction(this);
    actionSettings->setIcon(QIcon(":/icons/settings"));
    actionSettings->setText(tr("Settings"));
    popupMenu->addAction(actionSettings);
    connect(actionSettings, SIGNAL(triggered()),
            this, SLOT(on_settings())
    );

    popupMenu->addSeparator();



    //*** Quit
    actionQuit = popupMenu->addAction(QIcon(":/icons/quit"), tr("Quit"));
    connect(actionQuit, SIGNAL(triggered()), this, SLOT(on_quit()));

    //** Setup
    trayIcon->show();

    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();

} /* constructor */


//****************************************************************************
//** Settings Dialog
void MainObject::on_settings(){
    //SettingsWidget *sWidget = new SettingsWidget(this);
//    sWidget->show();
}



//****************************************************************************
//** Database Sanity Check
bool MainObject::db_sanity_check(){
    QSqlQuery query;
    query.prepare("select version from db_version;");
    if(!query.exec()){
        qDebug() << "Sanity=" << query.lastError();
        QStringList queries;
        queries.append("CREATE TABLE IF NOT EXISTS db_version( `version` varchar(20) );");
        queries.append("INSERT INTO db_version ( `version` )VALUES( 0.1 );");
        queries.append("CREATE TABLE IF NOT EXISTS addresses( name varchar(30), salutation varchar(30), company varchar(30), mobile varchar(30) );");
        for(int i = 0; i < queries.size(); ++i){
            qDebug() << queries.at(i);
            QSqlQuery q;
            //query.prepare(queries.at(i));
            if(!q.exec(queries.at(i))){
                qDebug() << "OOps=" << q.lastError();
                return false;
            }
        }
        return true;
    }
    return true;
}



//****************************************************************************
//** Quit
void MainObject::on_quit(){
    QCoreApplication::instance()->quit();
}


//****************************************************************************
//** Tray Icon
void MainObject::on_tray_icon(QSystemTrayIcon::ActivationReason reason){   
    //* Right click will show the context Menu above system tray
    //* Following will popup menu with single click on Top LEFT ??
    if(reason == QSystemTrayIcon::Trigger){
        QPoint p = QCursor::pos();
        trayIcon->contextMenu()->popup(p);
    }
}

