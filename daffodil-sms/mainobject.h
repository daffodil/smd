#ifndef MAINOBJECT_H
#define MAINOBJECT_H



#include <QtCore/QObject>
#include <QtCore/QSettings>


#include <QtSql/QSqlDatabase>

#include <QtGui/QSystemTrayIcon>
#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QLabel>
#include <QtGui/QWidgetAction>

//#include "settings/settingswidget.h"
//#include "mainwindows/mainwindow.h"

class MainObject : public QObject
{
Q_OBJECT
public:
    explicit MainObject(QObject *parent = 0);

    //MainWindow *mainWindow;

    //** Objects
    QSqlDatabase db;
    QSettings *settings;


      //* Widgets
    QSystemTrayIcon *trayIcon;
    QMenu *popupMenu;
    QWidgetAction *actionCallsign;
    QLabel *lblCallsign;

    QAction *actionSettings;

    QAction *actionQuit;

    bool db_sanity_check();
    bool db_create_provider(QString name, QString home, QString signup, QString login, QString prices);

signals:

public slots:
    void on_tray_icon(QSystemTrayIcon::ActivationReason reason);

    void on_settings();
    void on_quit();
};

#endif // MAINOBJECT_H
